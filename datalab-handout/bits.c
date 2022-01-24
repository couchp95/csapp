/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
// 1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  // comment
  int a = ~(~x & y);
  int b = ~(x & ~y);
  int c = ~(a & b);
  return c;
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  // comment
  return (1 << 31);
}
// 2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  int y = x + x + 1;
  int z = ~0;
  int a = !(x + 1);
  return (!(y ^ z) & !a);
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int b = 0xAA;
  int c = (b << 8) + b;
  int d = (c << 16) + c;
  return !((x & d) ^ d);
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) { return ~x + 1; }
// 3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0'
 * to '9') Example: isAsciiDigit(0x35) = 1. isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int a = !(x >> 6);
  int b = (x >> 4);
  int c = (x >> 5);
  int g = (x + 6) >> 4;
  return a & b & c & g;
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int a = !x;  // 1, x==0
  int b = !a;  // 0
  int e = ~a + 1;
  int f = ~b + 1;
  // printf("x:%x a:%x e:%x  b:%x f:%x \n", x, a, e, b, f);
  int r = (y & f) | (z & e);
  return r;
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // int sign = x >> 31;
  // x = (sign & ~x) | (~sign & x);

  int a = (x >> 31) & 1;
  int b = (y >> 31) & 1;
  int c = a ^ b;  // 0:same sign 1: +-

  int i = ~x + 1 + y;     // x,y both negative
  int j = (i >> 31) & 1;  // 0: x<=y, 1:x>y

  int r = (!c & !j) | (c & a);

  // printf("i:%d j:%x r:%x  a:%d b:%d c:%d\n", i, j, r, a, b, c);
  // printf("a:%d b:%d c:%d d:%d i:%d j:%d m:%d\n", a, b, c, d, i, j, m);
  // printf("x:%x y:%x r:%d (x<y):%d r1:%d r2:%d !c:%d\n", x, y, r, p, r1,
  // r2, !c);
  return (r);
}
// 4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x) {
  int i = ((x >> 16) | x);
  int m = (i | (i >> 8));
  int o = (m | (m >> 4));
  int k = ((o >> 2) | o);
  int p = (k | (k >> 1)) & 1;
  return p ^ 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int sign = (x >> 31) & 1;  // 1:negative
  int s = ~sign + 1;         // 0xffff: negitive, 0x0: positive

  int a = !!((x ^ s) >> 16);  // 1: first 16bits all 0,1
  int b = ~a + 1;             // 0: a=0, 0xffff: a=1
  int c = x >> (16 & b);      // x>>16: a=1

  int a1 = !!((c ^ s) >> 8);
  int b1 = ~a1 + 1;
  int c1 = c >> (8 & b1);

  int a2 = !!((c1 ^ s) >> 4);
  int b2 = ~a2 + 1;
  int c2 = c1 >> (4 & b2);

  int a3 = !!((c2 ^ s) >> 2);
  int b3 = ~a3 + 1;
  int c3 = c2 >> (2 & b3);

  int a4 = !!((c3 ^ s) >> 1);
  int b4 = ~a4 + 1;
  int c4 = c3 >> (1 & b4);

  int a5 = !!((c4 ^ s));
  int r = a5 + (a4) + (a3 << 1) + ((a2) << 2) + ((a1) << 3) + ((a << 4));
  /*
  printf("a:%x b:%d c:%x ", a, b, c);
  printf("a1:%x b1:%d c1:%x ", a1, b1, c1);
  printf("a2:%x b2:%d c2:%x ", a2, b2, c2);
  printf("a3:%x b3:%d c3:%x ", a3, b3, c3);
  printf("a4:%x b4:%d c4:%x ", a4, b4, c4);
  printf("a5:%x b5:%d \n", a5, b5);
  */
  return r + 1;
}
// float
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  int s = uf >> 31 & 1;
  int e = (uf << 1) >> 24;
  int m = (uf << 9) >> 9;
  // printf("s: %x  e: %x m: %x mm: %x\n", s, (e + 1), m, mm);
  int r;
  if (e == 0)
    if (m == 0)
      return (s << 31);
    else
      return (s << 31) | (m << 1);
  else if (e == 0xff) {
    if (m == 0)
      return uf;
    else
      return uf;
  }
  r = (s << 31) | ((e + 1) << 23 | m);
  return r;
}
/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  int s = uf >> 31 & 1;
  int e = ((uf << 1) >> 24) - 127;
  int ee = (uf >> 23) & 0xff;
  int m = (uf << 9) >> 9;
  int r = 0;
  int n;
  if ((ee == 0) && (m == 0)) return 0;
  if ((ee == 0xff) || (e > 31)) return 0x80000000u;
  if (e == 0) {
    if (s == 0)
      return (1);
    else
      return -1;
  }
  if ((e < 0)) return (0);
  n = e;
  while (n > 0) {
    r = r * 2 + (m >> 23) * 2;
    m = m << 1;
    n--;
  }
  // printf("uf:%x r:%d \n", uf, r);
  return (r | (s << 31));
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  int e = x + 127;
  int r;
  if (e < 0) return 0;
  if (e > 255) return 0x7f800000;
  // printf("x:%d e:%x r:%x\n", x, e, r);
  r = e << 23;
  return r;
}
