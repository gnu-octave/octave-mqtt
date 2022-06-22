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
## Flush a MQTT client connection
##
## @subsubheading Inputs
## @table @code
## @item obj
## A previously created octave_mqtt object
## @end table
##
## @subsubheading Outputs
## None
##
## @subsubheading Examples
## Open a client and flush the input
## @example
## @code {
## client = mqttclient("tcp://127.0.0.1);
## flush(client);
## }
## @end example
##
## @seealso{mqttclient}
## @end deftypefn

function flush(obj)
  if nargin != 1
    error ("Expected 1 arguments.");
  endif

  __mqtt_flush__(obj);
 
endfunction

%!test
%! client = mqttclient("tcp://broker.hivemq.com");
%! flush(client)
%! assert(isempty(peek(client)));
%! clear client
