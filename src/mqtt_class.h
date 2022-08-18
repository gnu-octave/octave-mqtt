// Copyright (C) 2022 John Donoghue <john.donoghue@ieee.org>
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
#ifndef MQTT_CLASS_H
#define MQTT_CLASS_H

// Octave Includes
#include <octave/oct.h>

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#ifdef HAVE_OCTAVE_OCT_TIME_H
# include <octave/oct-time.h>
#endif

// string
#include <string>

#include <iostream>

#include <errno.h>
#include <map>

#include <MQTTClient.h>

void init_types(void);

class msg_info
{
public:
  std::string topic;
  std::string data;
  OCTAVE__TIME ts;

  msg_info(const std::string &tp="",const std::string &d="", OCTAVE__TIME t = 0.0)
  {
    topic = tp;
    data = d;
    ts = t;
  }
};

class sub_info 
{
public:
  std::string callback;
  int qos;

  sub_info(int q, std::string cb="")
  {
    qos = q;
    callback = cb;
  }
};

class octave_mqtt : public OCTAVE_BASE_CLASS
{
public:
  /**
   * default constructor 
   */
  octave_mqtt (void);

  /**
   * deconstructor
   */
  ~octave_mqtt (void);

  // setting/gets
  void set_broker_address(const std::string &addr) { broker_address=addr; }
  std::string get_broker_address() const { return broker_address; }

  void set_client_id(const std::string &id) { client_id=id; }
  std::string get_client_id() const { return client_id; }

  void set_timeout(int t) { timeout=t; }
  int get_timeout() { return timeout; }

  void set_port(int p) { port=p; }
  int get_port() { return port; }

  void set_keep_alive_duration(int d) { keep_alive_duration=d; }
  int get_keep_alive_duration() { return keep_alive_duration; }

  bool get_connected();

  // SSL options
  void set_rootcert(const std::string &value) { rootcert=value; }
  void set_clientcert(const std::string &value) { clientcert=value; }
  void set_clientkey(const std::string &value) { clientkey=value; }
  void set_sslpassword(const std::string &value) { sslpassword=value; }

  std::map<std::string, sub_info> subscriptions() const { return subs; }

  msg_info read(const std::string &topic="");
  bool write(const std::string &topic, const std::string &msg, int qos, int retained);
  msg_info peek(const std::string &topic="");
  void flush();
  int poll(int t);

  void push_message(const msg_info &inf);

  bool create (const std::string &username, const std::string &password);
  void close (void);
  bool subscribe(const std::string &topic, int qos, std::string callback); 
  bool unsubscribe(const std::string &topic); 

  /**
   * Various properties of the octave_base_value datatype.
   */
  bool is_constant (void) const { return true;}
  bool is_defined (void) const { return true;}
  bool is_object (void) const { return true; }

  // required to use subsasn
  string_vector map_keys (void) const { return fieldnames; }
  dim_vector dims (void) const { static dim_vector dv(1, 1); return dv; }

  octave_base_value * clone (void) const;
  octave_base_value * empty_clone (void) const;
  octave_base_value * unique_clone (void);

 /**
  * Overloaded methods to print sock as the zeromq id
  */
  void print (std::ostream& os, bool pr_as_read_syntax = false) const;
  void print (std::ostream& os, bool pr_as_read_syntax = false); 
  void print_raw (std::ostream& os, bool pr_as_read_syntax) const;

 /**
  * overloaded methods to get properties
  */
  octave_value_list subsref (const std::string& type, const std::list<octave_value_list>& idx, int nargout);

  octave_value subsref (const std::string& type, const std::list<octave_value_list>& idx)
  {
    octave_value_list retval = subsref (type, idx, 1);
    return (retval.length () > 0 ? retval(0) : octave_value ());
  }

  octave_value subsasgn (const std::string& type, const std::list<octave_value_list>& idx, const octave_value& rhs);

private:
  octave_mqtt (const octave_mqtt &);

  MQTTClient client;

  std::string broker_address;
  std::string client_id;
  int timeout;
  int port;
  int keep_alive_duration;
  std::map<std::string, sub_info> subs;
  std::vector<msg_info> msgs;

  std::string rootcert;
  std::string clientcert;
  std::string clientkey;
  std::string sslpassword;

  string_vector fieldnames;
#ifdef DECLARE_OCTAVE_ALLOCATOR
  DECLARE_OCTAVE_ALLOCATOR
#endif
  DECLARE_OV_TYPEID_FUNCTIONS_AND_DATA
};

#endif // MQTT_CLASS_H
