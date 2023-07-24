## Copyright (C) 2022 John Donoghue <john.donoghue@ieee.org>
##
## This program is free software: you can redistribute it and/or modify it
## under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see
## <https://www.gnu.org/licenses/>.

## -*- texinfo -*- 
## @deftypefn {} {@var{client} =} mqttclient (@var{brokerAddr})
## @deftypefnx {} {@var{client} =} mqttclient (@var{brokerAddr}, [@var{name}, @var{value} ....])
## Create a MQTT client connection
##
## @subsubheading Inputs
## @table @code
## @item brokerAddr
## Name or IP address with protocol. ie: tcp://127.0.0.1.
## @item name, value
## Optional name / value pairs.
## @end table
##
## Known options are:
## @table @code
## @item Port
## Numeric port number to connect to (default 1883)
## @item Timeout
## Numeric timeout value in seconds (default 5)
## @item KeepAliveDuration
## Numeric keep alive value in seconds (default 60)
## @item ClientID
## String client Id 
## @item Username
## String username
## @item Password
## String password
## @item CARootCertificate
## String full file path to a root certificate file when using a secure connection
## @item ClientCertificate
## String full file path to a client certificate file when using a secure connection
## @item ClientKey
## String full file path to a private client key file when using a secure connection
## @item SSLPassword
## String Password to decrypt the client key file
## @end table
##
## @subsubheading Outputs
## @table @code
## @item client
## a octave_mqtt object
## @end table
##
## @subsubheading Properties
## A octave_mqtt object has the following properties:
## @table @code
## @item BrokerAddress
## Broker url
## @item Port
## Numeric port number to connect to (default 1883)
## @item Timeout
## Numeric timeout value in seconds (default 5)
## @item KeepAliveDuration
## Numeric keep alive value in seconds (default 60)
## @item ClientID
## String client Id 
## @end table
##
## @subsubheading Examples
## Create a new mqttclient
## @example
## @code {
## client = mqttclient("tcp://127.0.0.1");
## }
## @end example
##
## @end deftypefn

function obj = mqttclient(varargin)

  has_add_param = true;
  try
    p = inputParser();
    p.addParameter("test", 1);
  catch
    has_add_param = false;
  end_try_catch

  # parse args
  p = inputParser();
  p.CaseSensitive = false;
  p.FunctionName = 'mqttclient';
  p.KeepUnmatched = false;
  p.addRequired('brokerAddress', @ischar);
  if has_add_param
    p.addParameter('Port', 1883, @isnumeric);
    p.addParameter('Timeout', 5, @isnumeric);
    p.addParameter('KeepAliveDuration', 60, @isnumeric);
    p.addParameter('ClientID', "", @ischar);
    p.addParameter('Username', "", @ischar);
    p.addParameter('Password', "", @ischar);
    p.addParameter('CARootCertificate', "", @ischar);
    p.addParameter('ClientCertificate', "", @ischar);
    p.addParameter('ClientKey', "", @ischar);
    p.addParameter('SSLPassword', "", @ischar);
  else
    p.addParamValue('Port', 1883, @isnumeric);
    p.addParamValue('Timeout', 5, @isnumeric);
    p.addParamValue('KeepAliveDuration', 60, @isnumeric);
    p.addParamValue('ClientID', "", @ischar);
    p.addParamValue('Username', "", @ischar);
    p.addParamValue('Password', "", @ischar);
    p.addParamValue('CARootCertificate', "", @ischar);
    p.addParamValue('ClientCertificate', "", @ischar);
    p.addParamValue('ClientKey', "", @ischar);
    p.addParamValue('SSLPassword', "", @ischar);
  endif
  p.parse(varargin{:});

  obj = __mqtt_client__(varargin{:});
endfunction

%!error <Invalid call to mqttclient> mqttclient ();

%!error <Failed to create> mqttclient ("http://broker.hivemq.com");

%!test
%! client = mqttclient("tcp://broker.hivemq.com");
%! assert(client.BrokerAddress, "tcp://broker.hivemq.com");
%! assert(client.Port, 1883);
%! assert(client.Timeout, 5);
%! assert(client.KeepAliveDuration, 60);
%! assert(client.ClientID, "");
%! assert(client.Connected, true);
%! clear client

%!test
%! client = mqttclient("tcp://broker.hivemq.com", "Port", 1883, "Timeout", 10, "KeepAliveDuration", 30, "ClientID", "octave");
%! assert(client.BrokerAddress, "tcp://broker.hivemq.com");
%! assert(client.Port, 1883);
%! assert(client.Timeout, 10);
%! assert(client.KeepAliveDuration, 30);
%! assert(client.ClientID, "octave");
%! assert(client.Connected, true);
%! clear client
