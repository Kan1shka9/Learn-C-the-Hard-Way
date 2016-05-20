#include<stdio.h>

int main(int argc, char *argv[])
{
    puts("Hello world.");

    return 0;
}

/*
Extra Credits -> ex1
1.) Open the ex1 file in your text editor and change or delete random parts. Try running it and see what happens.

2.) Print out 5 more lines of text or something more complex than hello world.
#include<stdio.h>

int main(int argc, char *argv[])
{
    puts("Hello world.");
    puts("This is the first C program");
    puts("This way is a fun way to learn C");
    puts("I hope I stay true to the path");
    puts("I hope I master C when I complete reading this book");
    return 0;
}

3.) Run man 3 puts and read about this function and many others.
PUTS(3)                                                                                                Linux Programmer's Manual                                                                                                PUTS(3)

NAME
       fputc, fputs, putc, putchar, puts - output of characters and strings

SYNOPSIS
       #include <stdio.h>

       int fputc(int c, FILE *stream);

       int fputs(const char *s, FILE *stream);

       int putc(int c, FILE *stream);

       int putchar(int c);

       int puts(const char *s);

DESCRIPTION
       fputc() writes the character c, cast to an unsigned char, to stream.

       fputs() writes the string s to stream, without its terminating null byte ('\0').

       putc() is equivalent to fputc() except that it may be implemented as a macro which evaluates stream more than once.

       putchar(c); is equivalent to putc(c, stdout).

       puts() writes the string s and a trailing newline to stdout.

       Calls to the functions described here can be mixed with each other and with calls to other output functions from the stdio library for the same output stream.

       For nonlocking counterparts, see unlocked_stdio(3).

RETURN VALUE
       fputc(), putc() and putchar() return the character written as an unsigned char cast to an int or EOF on error.

       puts() and fputs() return a nonnegative number on success, or EOF on error.

CONFORMING TO
       C89, C99.

BUGS
       It is not advisable to mix calls to output functions from the stdio library with low-level calls to write(2) for the file descriptor associated with the same output stream; the results will be undefined and very probably not
       what you want.

SEE ALSO
       write(2), ferror(3), fopen(3), fputwc(3), fputws(3), fseek(3), fwrite(3), gets(3), putwchar(3), scanf(3), unlocked_stdio(3)

COLOPHON
       This page is part of release 3.44 of the Linux man-pages project.  A description of the project, and information about reporting bugs, can be found at http://www.kernel.org/doc/man-pages/.

GNU                                                                                                            2011-09-28                                                                                                       PUTS(3)
*/

/*
Extra Credits -> ex2
1.) Create an all: ex1 target that will build ex1 with just the command make.
CFLAGS=-Wall -g
all: ex1

clean:
        rm -f ex1

2.) Read man make to find out more information on how to run it.
MAKE(1)                                                                                      LOCAL USER COMMANDS                                                                                      MAKE(1)

NAME
       make - GNU make utility to maintain groups of programs

SYNOPSIS
       make [ -f makefile ] [ options ] ... [ targets ] ...

WARNING
       This  man  page  is an extract of the documentation of GNU make.  It is updated only occasionally, because the GNU project does not use nroff.  For complete, current documentation, refer to the Info
       file make.info which is made from the Texinfo source file make.texi.

DESCRIPTION
       The purpose of the make utility is to determine automatically which pieces of a large program need to be recompiled, and issue the commands to recompile them.  The manual describes the GNU implemen‐
       tation  of  make, which was written by Richard Stallman and Roland McGrath, and is currently maintained by Paul Smith.  Our examples show C programs, since they are most common, but you can use make
       with any programming language whose compiler can be run with a shell command.  In fact, make is not limited to programs.  You can use it to describe any task where some files must be  updated  auto‐
       matically from others whenever the others change.

       To  prepare  to  use  make, you must write a file called the makefile that describes the relationships among files in your program, and the states the commands for updating each file.  In a program,
       typically the executable file is updated from object files, which are in turn made by compiling source files.

       Once a suitable makefile exists, each time you change some source files, this simple shell command:

              make

       suffices to perform all necessary recompilations.  The make program uses the makefile data base and the last-modification times of the files to decide which of the files need  to  be  updated.   For
       each of those files, it issues the commands recorded in the data base.

       make executes commands in the makefile to update one or more target names, where name is typically a program.  If no -f option is present, make will look for the makefiles GNUmakefile, makefile, and
       Makefile, in that order.

       Normally you should call your makefile either makefile or Makefile.  (We recommend Makefile because it appears prominently near the beginning of a directory listing, right near other important files
       such  as  README.)   The first name checked, GNUmakefile, is not recommended for most makefiles.  You should use this name if you have a makefile that is specific to GNU make, and will not be under‐
       stood by other versions of make.  If makefile is `-', the standard input is read.

       make updates a target if it depends on prerequisite files that have been modified since the target was last modified, or if the target does not exist.

3.) Read man cc to find out more information on what the flags -Wall and -g do.
-Wall
           This enables all the warnings about constructions that some users
           consider questionable, and that are easy to avoid (or modify to
           prevent the warning), even in conjunction with macros.  This also
           enables some language-specific warnings described in C++ Dialect
           Options and Objective-C and Objective-C++ Dialect Options.

-g  	   Produce debugging information in the operating system's native
           format (stabs, COFF, XCOFF, or DWARF 2).  GDB can work with this
           debugging information.

4.) Research Makefiles online and see if you can improve this one even more.

5.) Find a Makefile in another C project and try to understand what it's doing.
*/
