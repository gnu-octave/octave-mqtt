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
## @deftypefn {} {@var{subs} =} subscribe (@var{obj}, @var{topic})
## @deftypefnx {} {@var{subs} =} subscribe (@var{obj}, @var{topic}, [@var{propname}, @var{propvalue} ....])
## Subscribe to a topic
##
## @subsubheading Inputs
## @table @code
## @item obj
## A previously created octave_mqtt object
## @item topic
## String topic to subscribe to.
## @item propname, propvalue
## Optional property name / value pairs.
## @end table
##
## Known property name / value pairs:
## @table @code
## @item QualityOfService
## Numeric QualityOfService [0-2] (default 0)
## @item Callback
## Callback function name or handle (default "")
## @end table
##
## @subsubheading Outputs
## @table @code
## @item subs
## a list of current subscriptions for this client.
## @end table
##
## @subsubheading Examples
## @example
## @code {
## client = mqttclient("tcp://127.0.0.1);
## subs = subscribe(client, "Test");
## }
## @end example
##
## @seealso{mqttclient, unsubscribe}
## @end deftypefn

function subs = subscribe(obj, topic, varargin)
  if nargin < 2
    error ("Expected at least 2 arguments.");
  endif

  if !ischar(topic)
    error ("Expected topic as string");
  endif

  qos = 0;
  callback = "";

  if mod (length(varargin), 2) != 0
    error ("Expected property name, value pairs");
  endif
  if !iscellstr (varargin (1:2:length(varargin)))
    error ("Expected property names to be strings");
  endif

  for i = 1:2:length(varargin)
    propname = tolower (varargin{i});
    propvalue = varargin{i+1};

    if strcmp (propname, "callback")
      if strcmp(class(propvalue), "function_handle")
        callback = func2str(propvalue);
      elseif ischar (propvalue)
        callback = propvalue;
      else
        error ("Callback should be a string or function handle")
      endif
    elseif strcmp (propname, "qualityofservice")
      if isnumeric (propvalue)
        qos = propvalue;
      else
        error ("QualityOfService should be numeric")
      endif
    else
      error ("unknown property '%s'", propname)
    endif
  endfor

  __mqtt_subscribe__(obj, topic, qos, callback);
  subs = obj.Subscriptions;
 
endfunction

%!test
%! client = mqttclient("tcp://broker.hivemq.com");
%! assert(isempty(client.Subscriptions));
%! subs = subscribe(client, "trubits/mqTsp61");
%! assert(!isempty(client.Subscriptions));
%! assert(subs(1).Topic, "trubits/mqTsp61");
%! assert(subs(1).QualityOfService, 0);
%! assert(subs(1).Callback, "");
%! subs = subscribe(client, "trubits/mqTsp48", "QualityOfService", 1);
%! assert(subs(1).Topic, "trubits/mqTsp48");
%! assert(subs(1).QualityOfService, 1);
%! assert(subs(1).Callback, "");
%! clear client
