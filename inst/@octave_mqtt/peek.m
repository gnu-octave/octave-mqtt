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
## @deftypefn {} {@var{msg} =} peek (@var{obj})
## @deftypefnx {} {@var{msg} =} peek (@var{obj}, @var{topic})
## Return the most recent message without removing it from the message queue.
##
## @subsubheading Inputs
## @table @code
## @item obj
## A previously created octave_mqtt object
## @item topic
## topic to match.
## @end table
##
## @subsubheading Outputs
## @table @code
## @item msg
## The most recent message.
## @end table
##
## If no topic is specified, the last message from any topic will be returned, otherwise the last
## matching the input topic.
##
## @subsubheading Examples
## @example
## @code {
## client = mqttclient("tcp://127.0.0.1);
## msg = peek(client);
## }
## @end example
##
## @end deftypefn

function msg = peek(obj, varargin)
  topic = "";
  if nargin > 2
    error ("Expected not more than 2 arguments.");
  elseif nargin == 2
    topic = varargin{1};
    if !ischar(topic)
      error ("topic should be a string")
    endif
  endif
  msg = __mqtt_peek__(obj, topic);
endfunction

%!test
%! client = mqttclient("tcp://broker.hivemq.com");
%! # peek should be empty as no subscriptions
%! assert(isempty(peek(client)));
%! assert(isempty(peek(client, "test1")));
%! clear client
