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
## @deftypefn {} {@var{msgs} =} read (@var{obj})
## @deftypefnx {} {@var{msgs} =} read (@var{obj}, @var{topic})
## Read available messages and remove from message queue. 
##
## @subsubheading Inputs
## @var{obj} - A previously created octave_mqtt object
##
## @var{topic} - topic to match.
##
## @subsubheading Outputs
## @var{msgs} - Messages from the message queue
##
## If no topic is specified, messages from any topic will be returned, otherwise from the
## matching input topic.
##
## @subsubheading Examples
## Open device 1
## @example
## @code {
## client = mqttclient("tcp://127.0.0.1);
## msgs = read(client, "test");
## }
## @end example
##
## @end deftypefn

function msg = read(obj, varargin)
  topic = "";
  if nargin > 2
    error ("Expected not more than 2 arguments.");
  elseif nargin == 2
    topic = varargin{1};
    if !ischar(topic)
      error ("topic should be a string")
    endif
  endif
  msg = __mqtt_read__(obj, topic);
endfunction

%!test
%! client = mqttclient("tcp://broker.hivemq.com");
%! # read should be empty as no subscriptions
%! assert(isempty(read(client)));
%! assert(isempty(read(client, "test1")));
%! clear client
