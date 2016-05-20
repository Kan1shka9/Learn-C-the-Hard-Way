#include <stdio.h>

int main(int argc, char *argv[])
{
    int bugs = 100;
    double bug_rate = 1.2;

    printf("You have %d bugs at the imaginary rate of %f.\n",
            bugs, bug_rate);

    long universe_of_defects = 1L * 1024L * 1024L * 1024L;
    printf("The entire universe has %ld bugs.\n",
            universe_of_defects);

    double expected_bugs = bugs * bug_rate;
    printf("You are expected to have %f bugs.\n",
            expected_bugs);

    double part_of_universe = expected_bugs / universe_of_defects;
    printf("That is only a %e portion of the universe.\n",
            part_of_universe);

    // this makes no sense, just a demo of something weird
    char nul_byte = '\0';
    int care_percentage = bugs * nul_byte;
    printf("Which means you should care %d%%.\n",
            care_percentage);

    return 0;
}

/*
Extra Credit
1.) Make the number you assign to universe_of_defects various sizes until you get a warning from the compiler.
#include <stdio.h>

int main(int argc, char *argv[])
{
    int bugs = 100;
    double bug_rate = 1.2;

    printf("You have %d bugs at the imaginary rate of %f.\n",
            bugs, bug_rate);

    long universe_of_defects = 1L * 1024L * 1024L * 1024L * 1024L * 1024L * 1024L * 1024L * 1024L;
    printf("The entire universe has %ld bugs.\n",
            universe_of_defects);

    double expected_bugs = bugs * bug_rate;
    printf("You are expected to have %f bugs.\n",
            expected_bugs);

    double part_of_universe = expected_bugs / universe_of_defects;
    printf("That is only a %e portion of the universe.\n",
            part_of_universe);

    // this makes no sense, just a demo of something weird
    char nul_byte = '\0';
    int care_percentage = bugs * nul_byte;
    printf("Which means you should care %d%%.\n",
            care_percentage);

    return 0;
}

Warning ->
cc -Wall -g    ex.c   -o ex
ex.c: In function ‘main’:
ex.c:11:59: warning: integer overflow in expression [-Woverflow]

2.) What do these really huge numbers actually print out?
You have 100 bugs at the imaginary rate of 1.200000.
The entire universe has 0 bugs.
You are expected to have 120.000000 bugs.
That is only a inf portion of the universe.
Which means you should care 0%.

3.) Change long to unsigned long and try to find the number that makes that one too big.
#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
    int bugs = 100;
    double bug_rate = 1.2;

    printf("You have %d bugs at the imaginary rate of %f.\n",
            bugs, bug_rate);

    unsigned long universe_of_defects = ULONG_MAX + 1UL;
    printf("The entire universe has %lu bugs.\n", universe_of_defects);

    double expected_bugs = bugs * bug_rate;
    printf("You are expected to have %f bugs.\n",
            expected_bugs);

    double part_of_universe = expected_bugs / universe_of_defects;
    printf("That is only a %e portion of the universe.\n",
            part_of_universe);

    // this makes no sense, just a demo of something weird
    char nul_byte = '\0';
    int care_percentage = bugs * nul_byte;
    printf("Which means you should care %d%%.\n",
            care_percentage);

    return 0;
}

Output ->
You have 100 bugs at the imaginary rate of 1.200000.
The entire universe has 0 bugs.
You are expected to have 120.000000 bugs.
That is only a inf portion of the universe.
Which means you should care 0%.

4.) Go search online to find out what unsigned does.
unsigned -> makes the integer non negative

5.) Try to explain to yourself (before I do in the next exercise) why you can multiply a char and an int.
Char are encoded as numbers using ASCII encoding
*/

/*
How To Break It

1.) Again, go through this and try breaking the printf by passing in the wrong arguments. See what happens when you try to print out that nul_byte variable too with %s vs. %c. When you break it, run it under Valgrind to see what it says about your breaking attempts.
Case 1 -> %s
devmac@devmac:~/Desktop/LCTHW$ cat cat.c 
#include <stdio.h>

int main(int argc, char *argv[])
{
    char null_byte = '\0';
    printf("%s \n", null_byte);

    return 0;
}
devmac@devmac:~/Desktop/LCTHW$ make cat
cc -Wall -g    cat.c   -o cat
cat.c: In function ‘main’:
cat.c:6:5: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘int’ [-Wformat=]
     printf("%s \n", null_byte);
     ^
devmac@devmac:~/Desktop/LCTHW$ ./cat 
(null) 
devmac@devmac:~/Desktop/LCTHW$ 

Case 2 -> %c
devmac@devmac:~/Desktop/LCTHW$ cat cat.c 
#include <stdio.h>

int main(int argc, char *argv[])
{
    char null_byte = '\0';
    printf("%c \n", null_byte);

    return 0;
}
devmac@devmac:~/Desktop/LCTHW$ make cat
cc -Wall -g    cat.c   -o cat
devmac@devmac:~/Desktop/LCTHW$ ./cat 
 
devmac@devmac:~/Desktop/LCTHW$ 
*/
