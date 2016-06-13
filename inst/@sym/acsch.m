%% Copyright (C) 2016 Colin B. Macdonald
%%
%% This file is part of OctSymPy.
%%
%% OctSymPy is free software; you can redistribute it and/or modify
%% it under the terms of the GNU General Public License as published
%% by the Free Software Foundation; either version 3 of the License,
%% or (at your option) any later version.
%%
%% This software is distributed in the hope that it will be useful,
%% but WITHOUT ANY WARRANTY; without even the implied warranty
%% of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
%% the GNU General Public License for more details.
%%
%% You should have received a copy of the GNU General Public
%% License along with this software; see the file COPYING.
%% If not, see <http://www.gnu.org/licenses/>.

%% -*- texinfo -*-
%% @documentencoding UTF-8
%% @defmethod @@sym acsch (@var{x})
%% Symbolic acsch function.
%%
%% Example:
%% @example
%% @group
%% @comment doctest: +SKIP
%% syms x
%% y = acsch(x)
%%   @result{} y = (sym) acsch(x)
%% @end group
%% @end example
%% (Note, this requires a recent version of SymPy > 1.0)
%%
%% Note: this file is autogenerated: if you want to edit it, you might
%% want to make changes to 'generate_functions.py' instead.
%%
%% @end defmethod

%% Author: Colin B. Macdonald
%% Keywords: symbolic

function y = acsch(x)
  if (nargin ~= 1)
    print_usage ();
  end
  y = uniop_helper (x, 'acsch');
end


%!shared x, d
%! d = 1;
%! x = sym('1');

%!test
%! if (python_cmd ('return Version(spver) > Version("1.0")'))
%! f1 = acsch(x);
%! f2 = acsch(d);
%! assert( abs(double(f1) - f2) < 1e-15 )
%! end

%!test
%! if (python_cmd ('return Version(spver) > Version("1.0")'))
%! D = [d d; d d];
%! A = [x x; x x];
%! f1 = acsch(A);
%! f2 = acsch(D);
%! assert( all(all( abs(double(f1) - f2) < 1e-15 )))
%! end
