#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    // go through each string in argv
    // why am I skipping argv[0]?
    for(i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };
    int num_states = 4;

    for(i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}

/*
How To Break It

1.) Take your favorite other language, and use it to run this program, but with as many command line arguments as possible. See if you can bust it by giving it way too many arguments.
#!/usr/bin/env python

import sys
from subprocess import call

if len(sys.argv) > 1:
    try:
        times = int(sys.argv[1])
        arguments = [str(i) for i in range(times)]
        arguments.insert(0, "./ex10")

        # Run ex10
        call(arguments)
    except Exception, e:
        print e

Output ->
devmac@devmac:~/Desktop/LCTHW$ python run10.py 5000000
[Errno 7] Argument list too long
devmac@devmac:~/Desktop/LCTHW$

2.) Initialize i to 0 and see what that does. Do you have to adjust argc as well or does it just work? Why does 0-based indexing work here?
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    // go through each string in argv
    // why am I skipping argv[0]?
    for(i = 0; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };
    int num_states = 4;

    for(i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}

Output ->
devmac@devmac:~/Desktop/LCTHW$ ./top qwe
arg 0: ./top
arg 1: qwe
state 0: California
state 1: Oregon
state 2: Washington
state 3: Texas
devmac@devmac:~/Desktop/LCTHW$

3.) Set num_states wrong so that it's a higher value and see what it does.
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    // go through each string in argv
    // why am I skipping argv[0]?
    for(i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };
    int num_states = 9;

    for(i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}

Output ->
devmac@devmac:~/Desktop/LCTHW$ ./top
state 0: California
state 1: Oregon
state 2: Washington
state 3: Texas
state 4: UW1▒VS▒e▒▒▒▒▒
tate 5: (null)
state 6: (null)
state 7: ▒$▒U▒
Segmentation fault (core dumped)
devmac@devmac:~/Desktop/LCTHW$
*/

/*
Extra Credit

1.) Figure out what kind of code you can put into the parts of a for-loop.
INITIALIZER; TEST; INCREMENTER

2.) Look up how to use the ',' (comma) character to separate multiple statements in the parts of the for-loop, but between the ';' (semicolon) characters.

3.) Read what a NULL is and try to use it in one of the elements of the states array to see what it'll print.
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    // go through each string in argv
    // why am I skipping argv[0]?
    for(i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon", NULL, "Texas"
    };
    int num_states = 4;

    for(i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}

Output ->
state 0: California
state 1: Oregon
state 2: (null)
state 3: Texas

4.) See if you can assign an element from the states array to the argv array before printing both. Try the inverse.
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    argv[1] = states[2];

    for(i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    int num_states = 4;

    for(i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}

Output ->
./prog asd
arg 1: Washington
state 0: California
state 1: Oregon
state 2: Washington
state 3: Texas

#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    states[1] = argv[1];

    for(i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    int num_states = 4;

    for(i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}

Output ->
devmac@devmac:~/Desktop/LCTHW$ ./bat gat
arg 1: gat
state 0: California
state 1: gat
state 2: Washington
state 3: Texas
devmac@devmac:~/Desktop/LCTHW$
*/
