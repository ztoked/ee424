/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
int bitNor(int, int);
int test_bitNor(int, int);
int tmax();
int test_tmax();
int sign(int);
int test_sign(int);
unsigned float_abs(unsigned);
unsigned test_float_abs(unsigned);
int copyLSB(int);
int test_copyLSB(int);
int allEvenBits();
int test_allEvenBits();
int byteSwap(int, int, int);
int test_byteSwap(int, int, int);
int reverseBytes(int);
int test_reverseBytes(int);
int bitMask(int, int);
int test_bitMask(int, int);
int isLess(int, int);
int test_isLess(int, int);
int howManyBits(int);
int test_howManyBits(int);
int isPower2(int);
int test_isPower2(int);
int float_f2i(unsigned);
int test_float_f2i(unsigned);
unsigned float_half(unsigned);
unsigned test_float_half(unsigned);
int bitParity(int);
int test_bitParity(int);
// Should be 15 puzzles, 2 level 1 puzzles, 5 level 2 puzzles, 3 level 3 puzzles, 5 level 4 puzzles
