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
## @deftypefn {} {} flush (@var{obj})
## @deftypefnx {} {} flush (@var{obj}, @var{topic})
## Flush a MQTT client connection
##
## @subsubheading Inputs
## @table @code
## @item obj
## A previously created octave_mqtt object
## @item topic
## Optional topic to clear from queue.
## @end table
##
## @subsubheading Outputs
## None
##
## @subsubheading Examples
## Open a client and flush the input
## @example
## @code {
## client = mqttclient("tcp://127.0.0.1");
## flush(client);
## }
## @end example
##
## Open a client and flush the input of only 'test' topics
## @example
## @code {
## client = mqttclient("tcp://127.0.0.1");
## flush(client, "test");
## }
## @end example
##
## @seealso{mqttclient}
## @end deftypefn

function flush(obj, topic="")
  if nargin < 0 || nargin > 2
    error ("Expected 1 or 2 arguments.");
  endif

  __mqtt_flush__(obj, topic);
 
endfunction

%!test
%! client = mqttclient("tcp://broker.hivemq.com");
%! flush(client)
%! assert(isempty(peek(client)));
%! flush(client, "test")
%! clear client
