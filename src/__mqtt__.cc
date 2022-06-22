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

#include <iostream>
#include <sstream>
#include <ctype.h>
#include <cmath>
#include <octave/oct.h>
#include <octave/version.h>
#include <octave/defun-dld.h>

#ifdef HAVE_CONFIG_H
#  include "./config.h"
#endif

#ifdef HAVE_OCTAVE_INTERPRETER_H
# include <octave/interpreter.h>
#endif

#include "mqtt_class.h"


// PKG_ADD: autoload ("__mqtt_client__", "__mqtt__.oct");
DEFUN_DLD(__mqtt_client__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __mqtt_client__\n \
Private function\n \
@end deftypefn")
{
  if ( args.length() == 0 || !args (0).is_string ())
    {
      print_usage ();
      return octave_value();
    }
  std::string brokeraddress = args (0).string_value();
  int port = 1883;
  int timeout = 5;
  int keepalive = 60;
  std::string clientid = "";
  std::string username = "";
  std::string password = "";

  if (args.length() > 1 && !(args.length() & 1)  == 1)
    {
      error ("Expected property name/value pairs");
      return octave_value ();
    }

  if (args.length() > 1)
    {
      // go through the properties
      for(int i=1;i<args.length();i+=2)
        {
          // first pair should be a property name
          if (! args (i).is_string ())
            {
              error ("Expected property name string");
              return octave_value ();
            }

          std::string name = args (i).string_value ();
          octave_value val = args (i+1);

          std::transform (name.begin (), name.end (), name.begin (), ::tolower);

          if (name == "port")
            {
              if (val.OV_ISINTEGER () || val.OV_ISFLOAT ())
	        {
                  port = val.int_value ();
		  if (port < 0)
		    {
                      error ("port must be a integer");
                      return octave_value();
		    }
		}
              else
                {
                  error ("port must be a integer");
                  return octave_value();
                }
            }
          else if (name == "timeout")
            {
              if (val.OV_ISINTEGER () || val.OV_ISFLOAT ())
                timeout = val.int_value ();
              else
                {
                  error ("timeout must be a integer or double");
                  return octave_value();
                }
            }
          else if (name == "keepaliveduration")
            {
              if (val.OV_ISINTEGER () || val.OV_ISFLOAT ())
                keepalive = val.int_value ();
              else
                {
                  error ("keepaliveduration must be a integer or double");
                  return octave_value();
                }
            }
          else if (name == "clientid")
            {
              if (val.is_string ())
                clientid = val.string_value ();
              else
                {
                  error ("clientid must be a string");
                  return octave_value();
                }
            }
          else if (name == "username")
            {
              if (val.is_string ())
                username = val.string_value ();
              else
                {
                  error ("username must be a string");
                  return octave_value();
                }
            }
          else if (name == "password")
            {
              if (val.is_string ())
                password = val.string_value ();
              else
                {
                  error ("password must be a string");
                  return octave_value();
                }
            }
 
          else
            {
              error ("unknown property '%s'", name.c_str());
              return octave_value();
            }
        }
    }

  init_types ();

  octave_mqtt * retvalue = new octave_mqtt ();
  retvalue->set_broker_address(brokeraddress);
  retvalue->set_port(port);
  retvalue->set_timeout(timeout);
  retvalue->set_keep_alive_duration(keepalive);
  retvalue->set_client_id(clientid);

  if ( retvalue->create (username, password) == false )
    {
      delete retvalue;
      return octave_value ();
    }

  return octave_value (retvalue);
}

// PKG_ADD: autoload ("__mqtt_subscribe__", "__mqtt__.oct");
DEFUN_DLD(__mqtt_subscribe__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __mqtt_subscribe__\n \
Private function.\n \
@end deftypefn")
{
  init_types ();

  if (args.length () != 4 || 
      args(0).type_id () != octave_mqtt::static_type_id ()
    || ! args(1).is_string ())
    {
      print_usage ();
      return octave_value (false);  
    }

  if (!args(2).OV_ISINTEGER () && !args(2).OV_ISFLOAT ())
    {
      error ("Expected QOS as a number");
    }

  if (!args(3).is_string ())
    {
      error ("Expected callback as string");
    }

  octave_mqtt * client = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  client = &((octave_mqtt &)rep);

  std::string topic = args (1).string_value ();
  int qos = args(2).int_value();
  std::string callback = args(3).string_value();

  bool ret = client->subscribe (topic, qos, callback);

  return octave_value (ret);
}

// PKG_ADD: autoload ("__mqtt_unsubscribe__", "__mqtt__.oct");
DEFUN_DLD(__mqtt_unsubscribe__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __mqtt_unsubscribe__\n \
Private function.\n \
@end deftypefn")
{
  init_types ();

  if (args.length () != 2 || 
      args(0).type_id () != octave_mqtt::static_type_id ()
    || ! args(1).is_string ())
    {
      print_usage ();
      return octave_value (false);  
    }

  octave_mqtt * client = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  client = &((octave_mqtt &)rep);

  std::string topic = args (1).string_value ();

  bool ret = client->unsubscribe (topic);

  return octave_value (ret);
}

// PKG_ADD: autoload ("__mqtt_write__", "__mqtt__.oct");
DEFUN_DLD(__mqtt_write__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __mqtt_write__\n \
Private function.\n \
@end deftypefn")
{
  init_types ();

  if (args.length () < 3 || 
      args(0).type_id () != octave_mqtt::static_type_id ()
    || ! args(1).is_string () || ! args(2).is_string())
    {
      print_usage ();
      return octave_value (false);  
    }

  std::string topic = args (1).string_value ();
  std::string msg = args (2).string_value ();
  int qos = 0;
  int retained = 0;;

  if (args.length() > 3)
    {
      if (!args(3).OV_ISINTEGER () && !args(3).OV_ISFLOAT ())
        {
          error ("Expected QOS as a number");
          return octave_value();
        }
      else
        qos = args(3).int_value();
    }

  if (args.length() > 4)
    {
      if (!args(4).OV_ISINTEGER () && !args(4).OV_ISFLOAT () && !args(4).OV_ISLOGICAL ())
        {
          error ("Expected retained as a number");
        }
      else
        retained = args(4).int_value();
    }

  octave_mqtt * client = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  client = &((octave_mqtt &)rep);

  bool ret = client->write (topic, msg, qos, retained);

  return octave_value (ret);
}

// PKG_ADD: autoload ("__mqtt_read__", "__mqtt__.oct");
DEFUN_DLD(__mqtt_read__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __mqtt_read__\n \
Private function\n \
@end deftypefn")
{
  init_types ();

  if (args.length () != 2 || 
      args(0).type_id () != octave_mqtt::static_type_id ()
    || ! args(1).is_string ())
    {
      print_usage ();
      return octave_value (false);  
    }

  octave_mqtt * client = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  client = &((octave_mqtt &)rep);

  std::string topic = args (1).string_value ();

  // get all the matching messages
  msg_info m = client->read (topic);
  std::vector<msg_info> messages;
  while (m.topic.length())
    {
      messages.push_back(m);
      m = client->read (topic);
    }

  octave_map map;
  Cell times(dim_vector (1, messages.size()));
  Cell topics(dim_vector (1,messages.size()));
  Cell data(dim_vector (1,messages.size()));

  for(int i=0;i<messages.size();i++)
    {
      m = messages[i];

      times(i) = m.ts;
      topics(i) = m.topic;
      data(i) = m.data;
    }

  map.setfield("Time", times);
  map.setfield("Topic", topics);
  map.setfield("Data", data);
	
  return octave_value (map);
}

// PKG_ADD: autoload ("__mqtt_peek__", "__mqtt__.oct");
DEFUN_DLD(__mqtt_peek__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __mqtt_peek__\n \
Private function.\n \
@end deftypefn")
{
  init_types ();

  if (args.length () != 2 || 
      args(0).type_id () != octave_mqtt::static_type_id ()
    || ! args(1).is_string ())
    {
      print_usage ();
      return octave_value (false);  
    }

  octave_mqtt * client = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  client = &((octave_mqtt &)rep);

  std::string topic = args (1).string_value ();

  msg_info m = client->peek (topic);

  octave_map map;
  if (m.topic.length())
    {
      Cell time(dim_vector (1, 1));
      Cell topic(dim_vector (1, 1));
      Cell data(dim_vector (1, 1));

      time(0) = m.ts;
      topic(0) = m.topic;
      data(0) = m.data;

      map.setfield("Time", time);
      map.setfield("Topic", topic);
      map.setfield("Data", data);
    }
  else
    {
      Cell time(dim_vector (1, 0));
      Cell topic(dim_vector (1, 0));
      Cell data(dim_vector (1, 0));

      map.setfield("Time", time);
      map.setfield("Topic", topic);
      map.setfield("Data", data);	
    }
  return octave_value (map);
}

// PKG_ADD: autoload ("__mqtt_flush__", "__mqtt__.oct");
DEFUN_DLD(__mqtt_flush__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __mqtt_flush__\n \
Private function.\n \
@end deftypefn")
{
  init_types ();

  if (args.length () != 1 || 
      args(0).type_id () != octave_mqtt::static_type_id ())
    {
      print_usage ();
      return octave_value (false);  
    }

  octave_mqtt * client = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  client = &((octave_mqtt &)rep);

  client->flush();

  bool ret = true;

  return octave_value (ret);
}

#if 0
%!assert(exist("__mqtt_client__"), 3)
%!assert(exist("__mqtt_subscribe__"), 3)
%!assert(exist("__mqtt_unsubscribe__"), 3)
%!assert(exist("__mqtt_peek__"), 3)
%!assert(exist("__mqtt_read__"), 3)
%!assert(exist("__mqtt_write__"), 3)
%!assert(exist("__mqtt_flush__"), 3)
#endif

