/*

Copyright (C) 2002 Ben Sapp

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/

#if !defined (octave_ex_h)
#define octave_ex_h 1

#include <ginac/ginac.h>
#include <octave/ov-complex.h>
#include <octave/ov-scalar.h>
#include "ov-sym.h"
#include "ov-vpa.h"


class octave_complex;
class octave_scalar;

class 
octave_ex : public octave_base_value
{
public:
  octave_ex(void):octave_base_value() {}

  octave_ex(octave_ex &ox);
  octave_ex(GiNaC::ex expression);
  octave_ex(octave_sym &osym);
  octave_ex(GiNaC::symbol sym);
  octave_ex(octave_complex &cmplx);
  octave_ex(Complex z);
  octave_ex(octave_scalar &s);
  octave_ex(double d);

  ~octave_ex() {}
  
  octave_ex& operator=(const octave_ex&);

  GiNaC::ex ex_value(bool = false) const
    {
      return x;
    }
  
  octave_value *clone (void) 
    { 
      return new octave_ex (*this); 
    }
  
  int rows (void) const { return 1; }
  int columns (void) const { return 1; }
  
  bool is_constant (void) const { return true; }
  bool is_defined (void) const { return true; }

  bool valid_as_scalar_index(void) const {return false;}

  bool is_true(void) const { return true; }
   
  octave_value uminus (void) const { return new octave_ex(-x); }

  void increment (void) { x = x+1;}

  void decrement (void) { x = x-1;}
  
  void print(ostream& os,bool pr_as_read_syntax) const;
  
private:
  GiNaC::ex x;

  DECLARE_OCTAVE_ALLOCATOR

  DECLARE_OV_TYPEID_FUNCTIONS_AND_DATA  

};

#endif 

/*
;;; Local Variables: ***
;;; mode: C++ ***
;;; End: ***
*/
