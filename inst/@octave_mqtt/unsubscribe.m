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
## @deftypefn {} {} unsubscribe (@var{obj}, @var{topic})
## Unsubscribe from @var{topic}
##
## @subsubheading Inputs
## @table @code
## @item obj
## A previously created octave_mqtt object
## @item topic
## string topic name.
## @end table
##
## @subsubheading Outputs
## None
##
## @subsubheading Examples
## @example
## @code {
## client = mqttclient("tcp://127.0.0.1);
## subscribe(client, "test1");
## unsubscribe(client, "test1");
## }
## @end example
##
## @seealso{mqttclient, subscribe}
## @end deftypefn

function unsubscribe(obj, topic)
  if nargin != 2
    error ("Expected 2 arguments.");
  endif

  if !ischar(topic)
    error ("Expected topic as a string");
  endif

  __mqtt_unsubscribe__(obj, topic);
 
endfunction

%!test
%! client = mqttclient("tcp://broker.hivemq.com");
%! assert(isempty(client.Subscriptions));
%! subs = subscribe(client, "trubits/mqTsp61");
%! assert(!isempty(client.Subscriptions));
%! unsubscribe(client, "trubits/mqTsp61");
%! assert(isempty(client.Subscriptions));
%! clear client
