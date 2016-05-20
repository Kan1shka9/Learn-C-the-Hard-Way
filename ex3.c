#include <stdio.h>

int main()
{
    int age = 10;
    int height = 72;

    printf("I am %d years old.\n", age);
    printf("I am %d inches tall.\n", height);

    return 0;
}

/*
External Research

Escape codes
http://en.cppreference.com/w/cpp/language/escape

Format sequences
https://www.le.ac.uk/users/rjm1/cotter/page_30.htm
*/

/*
Extra Credit
1.) Find as many other ways to break ex3.c as you can.

2.) Run man 3 printf and read about the other '%' format characters you can use. These should look familiar if you used them in other languages (printf is where they come from).
 The conversion specifier
       A character that specifies the type of conversion to be applied.  The conversion specifiers and their meanings are:

       d, i   The int argument is converted to signed decimal notation.  The precision, if any, gives the minimum number of digits that must appear; if the converted value requires fewer digits, it is padded on the left with zeros.
              The default precision is 1.  When 0 is printed with an explicit precision 0, the output is empty.

       o, u, x, X
              The unsigned int argument is converted to unsigned octal (o), unsigned decimal (u), or unsigned hexadecimal (x and X) notation.  The letters abcdef are used for x conversions; the letters ABCDEF are used for X conver‐
              sions.  The precision, if any, gives the minimum number of digits that must appear; if the converted value requires fewer digits, it is padded on the left with zeros.  The default precision is 1.  When  0  is  printed
              with an explicit precision 0, the output is empty.

       e, E   The double argument is rounded and converted in the style [-]d.ddde±dd where there is one digit before the decimal-point character and the number of digits after it is equal to the precision; if the precision is miss‐
              ing, it is taken as 6; if the precision is zero, no decimal-point character appears.  An E conversion uses the letter E (rather than e) to introduce the exponent.  The exponent always contains at least two digits;  if
              the value is zero, the exponent is 00.

       f, F   The  double  argument  is  rounded  and converted to decimal notation in the style [-]ddd.ddd, where the number of digits after the decimal-point character is equal to the precision specification.  If the precision is
              missing, it is taken as 6; if the precision is explicitly zero, no decimal-point character appears.  If a decimal point appears, at least one digit appears before it.

              (The SUSv2 does not know about F and says that character string representations for infinity and NaN may be made available.  The C99 standard specifies "[-]inf" or "[-]infinity" for infinity,  and  a  string  starting
              with "nan" for NaN, in the case of f conversion, and "[-]INF" or "[-]INFINITY" or "NAN*" in the case of F conversion.)

       g, G   The double argument is converted in style f or e (or F or E for G conversions).  The precision specifies the number of significant digits.  If the precision is missing, 6 digits are given; if the precision is zero, it
              is treated as 1.  Style e is used if the exponent from its conversion is less than -4 or greater than or equal to the precision.  Trailing zeros are removed from the fractional part of  the  result;  a  decimal  point
              appears only if it is followed by at least one digit.

       a, A   (C99;  not  in SUSv2) For a conversion, the double argument is converted to hexadecimal notation (using the letters abcdef) in the style [-]0xh.hhhhp±; for A conversion the prefix 0X, the letters ABCDEF, and the expo‐
              nent separator P is used.  There is one hexadecimal digit before the decimal point, and the number of digits after it is equal to the precision.  The default precision suffices for an exact representation of the value
              if  an exact representation in base 2 exists and otherwise is sufficiently large to distinguish values of type double.  The digit before the decimal point is unspecified for nonnormalized numbers, and nonzero but oth‐
              erwise unspecified for normalized numbers.

       c      If no l modifier is present, the int argument is converted to an unsigned char, and the resulting character is written.  If an l modifier is present, the wint_t (wide character) argument is converted  to  a  multibyte
              sequence by a call to the wcrtomb(3) function, with a conversion state starting in the initial state, and the resulting multibyte string is written.

       s      If  no  l  modifier is present: The const char * argument is expected to be a pointer to an array of character type (pointer to a string).  Characters from the array are written up to (but not including) a terminating
              null byte ('\0'); if a precision is specified, no more than the number specified are written.  If a precision is given, no null byte need be present; if the precision is not specified, or is greater than the  size  of
              the array, the array must contain a terminating null byte.

              If  an  l modifier is present: The const wchar_t * argument is expected to be a pointer to an array of wide characters.  Wide characters from the array are converted to multibyte characters (each by a call to the wcr‐
              tomb(3) function, with a conversion state starting in the initial state before the first wide character), up to and including a terminating null wide character.  The resulting multibyte characters are  written  up  to
              (but  not  including)  the terminating null byte.  If a precision is specified, no more bytes than the number specified are written, but no partial multibyte characters are written.  Note that the precision determines
              the number of bytes written, not the number of wide characters or screen positions.  The array must contain a terminating null wide character, unless a precision is given and it is so small that the  number  of  bytes
              written exceeds it before the end of the array is reached.

       C      (Not in C99, but in SUSv2.)  Synonym for lc.  Don't use.

       S      (Not in C99, but in SUSv2.)  Synonym for ls.  Don't use.

       p      The void * pointer argument is printed in hexadecimal (as if by %#x or %#lx).

       n      The number of characters written so far is stored into the integer indicated by the int * (or variant) pointer argument.  No argument is converted.

       m      (Glibc extension.)  Print output of strerror(errno).  No argument is required.

       %      A '%' is written.  No argument is converted.  The complete conversion specification is '%%'.

3.) Add ex3 to your Makefile's all list. Use this to make clean all and build all your exercises so far.
CFLAGS=-Wall -g

FILES = ex1  ex3

all: $(FILES)

clean:
        rm -f $(FILES)

4.) Add ex3 to your Makefile's clean list as well. Now use make clean will remove it when you need to.
*/
