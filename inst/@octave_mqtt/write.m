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
## @deftypefn {} {} write (@var{obj}, @var{topic}, @var{value})
## @deftypefnx {} {} write (@var{obj}, @var{topic}, @var{value}, [@var{propname}, @var{propvalue} ....])
## Write @var{value} to @var{topic}.
##
## @subsubheading Inputs
## @table @code
## @item obj
## A previously created octave_mqtt object
## @item topic
## String topic to write to.
## @item value
## String value to write to topic.
## @item propname, propvalue
## Optional property name / value pairs.
## @end table
##
## Known property options are:
## @table @code
## @item QualityOfService
## Numeric QualityOfService [0-2] (default 0)
## @item Retain
## Boolean flag value for retaining message (default false)
## @end table
##
## @subsubheading Outputs
## @table @code
## @item client
## A octave_mqtt object.@*
## @end table
##
## @subsubheading Examples
## Open a client connection and write some values.
## @example
## @code {
## client = mqttclient("tcp://127.0.0.1");
## write(client, "mytopic", "test1");
## write(client, "mytopic", "test1", "QualityOfService", 1);
## }
## @end example
##
## @seealso{mqttclient}
## @end deftypefn

function write(obj, topic, value, varargin)
  if nargin < 3
    error ("Expected at least 3 arguments.");
  endif

  if mod (length(varargin), 2) != 0
    error ("Expected property name, value pairs");
  endif
  if !iscellstr (varargin (1:2:length(varargin)))
    error ("Expected property names to be strings");
  endif

  qos = 0;
  retain = false;

  for i = 1:2:length(varargin)
    propname = tolower (varargin{i});
    propvalue = varargin{i+1};

    if strcmp (propname, "retain")
      if isnumeric (propvalue) || islogical(propvalue)
        retain = propvalue;
      else
        error ("Retain should be a logical")
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

  __mqtt_write__(obj, topic, value, qos, retain);
 
endfunction


