// Copyright (C) 2014-2018 John Donoghue <john.donoghue@ieee.org>
//
// This program is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free Software
// Foundation; either version 3 of the License, or (at your option) any later
// version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along with
// this program; if not, see <http://www.gnu.org/licenses/>.

// Octave Includes
#include <octave/oct.h>

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include "mqtt_class.h"
#include <octave/oct-map.h>

#include <octave/quit.h>

#include <pthread.h>
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

class Locker
{
  pthread_mutex_t mutex;
public:
  Locker(pthread_mutex_t m)
  {
    mutex = m;
    pthread_mutex_lock(&mutex);
  }
  virtual ~Locker()
  {
    pthread_mutex_unlock(&mutex);
  }
};

static void
delivered(void *context, MQTTClient_deliveryToken dt)
{
    //debug("Message with token value %d delivery confirmed\n", dt);
}

static int
msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    octave_mqtt *client = (octave_mqtt *)context;
    OCTAVE__TIME ts;
    std::string topic = "";
    if(topicLen == 0)
      topic = topicName;
    else
      topic = std::string(topicName, topicLen);

    client->push_message(msg_info(topic, std::string((const char*)message->payload, message->payloadlen), ts));

    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

static void
connlost(void *context, char *cause)
{
    printf("\nConnection lost\n");
    printf("     cause: %s\n", cause);
}

static std::string
error_string(int code)
{
  std::string errstr = "";

  if(code == 0) return "";

  const char *err = MQTTClient_strerror(code);
  if(err)
    errstr = std::to_string(code) + ": " + std::string(err);
  else
    errstr = std::to_string(code);

  return errstr;
}


#ifdef DEFINE_OCTAVE_ALLOCATOR 
DEFINE_OCTAVE_ALLOCATOR (octave_mqtt);
#endif
DEFINE_OV_TYPEID_FUNCTIONS_AND_DATA (octave_mqtt, "octave_mqtt", "octave_mqtt");

octave_mqtt::octave_mqtt (void)
 : fieldnames(7)
{
  client = 0;
  fieldnames[0] = "Subscriptions";
  fieldnames[1] = "Port";
  fieldnames[2] = "BrokerAddress";
  fieldnames[3] = "Timeout";
  fieldnames[4] = "ClientID";
  fieldnames[5] = "KeepAliveDuration";
  fieldnames[6] = "Connected";
}

octave_mqtt::octave_mqtt (const octave_mqtt &s)
{
  // should never be called
  client = 0;
  fieldnames = s.fieldnames;
}

octave_mqtt::~octave_mqtt(void)
{
  close ();
}

octave_base_value *
octave_mqtt::empty_clone (void) const 
{
  return new octave_mqtt();
}

octave_base_value *
octave_mqtt::clone (void) const 
{
  return new octave_mqtt (*this);
}

octave_base_value *
octave_mqtt::unique_clone (void) 
{
  OV_COUNT++;
  return this;
}

bool
octave_mqtt::create (const std::string &username, const std::string &password)
{
  if (client)
    {
      error ("mqtt: Already created\n");
      return false;
    }

  std::string addr = broker_address + ":" + std::to_string(port);

  int rc;
  if ((rc = MQTTClient_create(&client, addr.c_str(), client_id.c_str(),
    MQTTCLIENT_PERSISTENCE_NONE, NULL)) != MQTTCLIENT_SUCCESS)
    {
      error("Failed to create - %s", error_string(rc).c_str());
      return false;
    }

  if ((rc = MQTTClient_setCallbacks(client, this, connlost, msgarrvd, delivered))
    != MQTTCLIENT_SUCCESS)
    {
      error("Failed to set callbacks - %s", error_string(rc).c_str());
      return false;
    }

  MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
  conn_opts.keepAliveInterval = 20;
  conn_opts.cleansession = 1;
  if (username.length() > 0)
    conn_opts.username = username.c_str();
  if (password.length() > 0)
    conn_opts.password = password.c_str();

  std::string ssloptstr = rootcert + clientcert + clientkey + sslpassword;

  MQTTClient_SSLOptions sslopts = MQTTClient_SSLOptions_initializer;
  if (ssloptstr.length() > 0)
    {

      if (rootcert.length() > 0)
        sslopts.trustStore = rootcert.c_str();
      if (clientcert.length() > 0)
        sslopts.keyStore = clientcert.c_str();
      if (clientkey.length() > 0)
        sslopts.privateKey = clientkey.c_str();
      if (sslpassword.length() > 0)
        sslopts.privateKeyPassword = sslpassword.c_str();

#ifdef MQTTVERSION_3_1
      if (sslopts.struct_version >= MQTTVERSION_3_1)
	sslopts.verify = 1;
#endif
      conn_opts.ssl = &sslopts;
    }

  if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
      error("Failed to connect - %s", error_string(rc).c_str());
      return false;
    }
  return true;
}

void
octave_mqtt::close (void)
{
  Locker lock(mutex);
  if (client)
  {
    if (MQTTClient_isConnected(client))
      {
        MQTTClient_disconnect(client, 0);
      }

    MQTTClient_destroy(&client);
    client = 0;
  }
}

void
octave_mqtt::print (std::ostream& os, bool pr_as_read_syntax) const
{
  print_raw (os, pr_as_read_syntax);
  newline (os);
}

void
octave_mqtt::print (std::ostream& os, bool pr_as_read_syntax)
{
  print_raw (os, pr_as_read_syntax);
  newline (os);
}

void
octave_mqtt::print_raw (std::ostream& os, bool pr_as_read_syntax) const
{
  os << "  Client with properties"; newline (os);
  
  if(client)
    {
      os << "    BrokerAddress: " << broker_address; newline(os);
      os << "             Port: " << port; newline(os);
      os << "         ClientID: " << client_id; newline(os);
      os << "          Timeout: " << timeout; newline(os);
      os << "KeepAliveDuration: " << keep_alive_duration; newline(os);
      os << "    Subscriptions: [" << subs.size() << "x3] table"; newline(os);
      os << "        Connected: " << MQTTClient_isConnected(client); newline(os);
    }
  else
    {
      os << "    Invalid"; newline(os);
    }
}

bool octave_mqtt::get_connected() 
{
  if (client)
    return MQTTClient_isConnected(client);
  else
    return false;
}

octave_value_list
octave_mqtt::subsref (const std::string& type, const std::list<octave_value_list>& idx, int nargout)
{
  octave_value_list retval;
  int skip = 1;

  switch (type[0])
    {
    default:
      error ("octave_mqtt object cannot be indexed with %c", type[0]);
      break;
    case '.':
      {
        std::string prop = (idx.front ()) (0).string_value();
	if (prop == "Subscriptions")
	{
          Cell topic(dim_vector (1, subs.size()));
          Cell qos(dim_vector (1, subs.size()));
          Cell callback(dim_vector (1, subs.size()));
	  int idx = 0;
          for(auto i : subs) 
	  {
	    topic(idx) = i.first;
	    qos(idx) = i.second.qos;
	    callback(idx) = i.second.callback;
	    idx++;
	  }
          octave_map map;
	  map.setfield("Topic", topic);
	  map.setfield("QualityOfService", qos);
	  map.setfield("Callback", callback);
	  retval(0) = map;
	}
	else if (prop == "BrokerAddress")
	  retval(0) = get_broker_address();
	else if (prop == "Port")
	  retval(0) = octave_value(get_port());
	else if (prop == "Timeout")
	  retval(0) = octave_value(get_timeout());
	else if (prop == "Connected")
	  retval(0) = octave_value(get_connected());
	else if (prop == "KeepAliveDuration")
	  retval(0) = octave_value(get_keep_alive_duration());
	else if (prop == "ClientID")
	  retval(0) = get_client_id();
	else
	  error ("Unkown property '%s'", prop.c_str());
      }
      break;
    }

  if (idx.size () > 1 && type.length () > 1)
    retval = retval (0).next_subsref (nargout, type, idx, skip);

  return retval;
}

octave_value
octave_mqtt::subsasgn (const std::string& type, const std::list<octave_value_list>& idx, const octave_value& rhs)
{
  octave_value retval;

  switch (type[0])
    {
    default:
      error ("octave_mqtt object cannot be indexed with %c", type[0]);
      break;
/*
    All properies are readonly
    case '.':
      if (type.length () == 1)
        {
          octave_value_list ovl;
          // inc ref count as assign this to octave_value
          OV_COUNT++; 
          ovl (0) = octave_value (this);
          ovl (1) = (idx.front ()) (0);
          ovl (2) = rhs;
          OCTAVE__FEVAL (std::string ("__zmq_properties__"), ovl, 0);
          OV_COUNT++;
          retval = octave_value (this);
        }
      else if (type.length () > 1 && type[1] == '.')
        {
          // pass along any further assignments
          octave_value_list u = subsref (type.substr (0, 1), idx, 1);
          if (u.length() > 0)
            {
              std::list<octave_value_list> next_idx (idx);
              next_idx.erase (next_idx.begin ());
              u (0).subsasgn(type.substr (1), next_idx, rhs);
              OV_COUNT++;
              retval = octave_value (this);
            } 
        }
      else
        {
          error ("octave_mqtt invalid index");
        }
*/
    }
  return retval;
}

bool
octave_mqtt::subscribe(const std::string &topic, int qos, std::string callback)
{
  bool ok = false;
  int rc;

  if(!client)
    error ("No client");

  auto search = subs.find(topic);
  if (search != subs.end())
    {
      error("Already subscribed to %s", topic.c_str());
    }
  else if ((rc = MQTTClient_subscribe(client, topic.c_str(), qos)) != MQTTCLIENT_SUCCESS)
    {
      error("Failed to subscribe - %s", error_string(rc).c_str());
    }
  else
    {
      ok = true;
      subs.insert({ topic, sub_info(qos, callback) });
    }

  return ok;
}

bool
octave_mqtt::unsubscribe(const std::string &topic)
{
  bool ok = false;
  int rc;

  if(!client)
    error ("No client");

  auto search = subs.find(topic);
  if (search == subs.end())
    {
      error("Not subscribed to %s", topic.c_str());
    }
  else if ((rc = MQTTClient_unsubscribe(client, topic.c_str())) != MQTTCLIENT_SUCCESS)
    {
      error("Failed to unsubscribe - %s", error_string(rc).c_str());
    }
  else
    {
      ok = true;
      subs.erase(search);
    }

  return ok;
}

void
octave_mqtt::flush()
{
  Locker lock(mutex);
  msgs.erase(msgs.begin(), msgs.end());
}

void
octave_mqtt::push_message(const msg_info &m)
{
  Locker lock(mutex);

  msgs.push_back(m);

  // do we have a callback configured for this topic
  auto search = subs.find(m.topic);
  if (search != subs.end())
    {
      sub_info s = search->second;

      if (s.callback.length() > 0)
        {
          try
            {
              octave_value_list ret = OCTAVE__FEVAL (s.callback, ovl (m.topic, m.data), 0);
            }
          catch (const OCTAVE_EXECUTION_EXCEPTION &e)
            {
#ifdef HAS_OCTAVE_EXCEPTION_MESSAGE
              warning("mqttcallback: %s", e.OCTAVE_EXCEPTION_MESSAGE().c_str());
#else
              warning("mqttcallback: execution exception occured");
#endif
            }
        }
    }
}

msg_info
octave_mqtt::peek(const std::string &topic)
{
  Locker lock(mutex);
  for (auto it = msgs.rbegin(); it != msgs.rend(); ++it)
    {
      if((*it).topic == topic || topic == "")
        return *it;
    }

  return msg_info();
}


bool
octave_mqtt::write(const std::string &topic, const std::string &msg, int qos, int retained)
{
  char m[1024];
  int len = msg.length();

  if (len > (int)sizeof(m))
    len = (int)sizeof(m);

  if(!client)
    error ("No client");

  memcpy(m, msg.c_str(), len);

  MQTTClient_message pubmsg = MQTTClient_message_initializer;
  MQTTClient_deliveryToken token;
  pubmsg.payload = m;
  pubmsg.payloadlen = len;
  pubmsg.qos = qos;
  pubmsg.retained = retained;

  int rc = MQTTClient_publishMessage(client, topic.c_str(), &pubmsg, &token);

  if (rc != MQTTCLIENT_SUCCESS)
    {
      error("Failed to publishMessage - %s", error_string(rc).c_str());
      return false;
    }

  return true;
}

msg_info
octave_mqtt::read(const std::string &topic)
{
  Locker lock(mutex);

  for (auto it = msgs.begin(); it != msgs.end(); ++it)
    {
      if ((*it).topic == topic || topic == "")
        {
          msg_info d = *it;
          msgs.erase(it);
          return d;
       }
    }

  return msg_info();
}

static bool type_loaded = false;

void
init_types(void)
{
  if (!type_loaded)
    {
     octave_mqtt::register_type ();
     type_loaded = true;
    }
}

