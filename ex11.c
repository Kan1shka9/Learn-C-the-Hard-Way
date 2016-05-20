#include <stdio.h>

int main(int argc, char *argv[])
{
    // go through each string in argv

    int i = 0;
    while(i < argc) {
        printf("arg %d: %s\n", i, argv[i]);
        i++;
    }

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;
    i = 0;  // watch for this
    while(i < num_states) {
        printf("state %d: %s\n", i, states[i]);
        i++;
    }

    return 0;
}

/*
How To Break It

1.) Forget to initialize the first int i; so have it loop wrong.
#include <stdio.h>

int main(int argc, char *argv[])
{
    // go through each string in argv

    while(i < argc) {
        printf("arg %d: %s\n", i, argv[i]);
        i++;
    }

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;
    i = 0;  // watch for this
    while(i < num_states) {
        printf("state %d: %s\n", i, states[i]);
        i++;
    }

    return 0;
}

devmac@devmac:~/Desktop/LCTHW$ make bat
cc -Wall -g    bat.c   -o bat
bat.c: In function ‘main’:
bat.c:7:11: error: ‘i’ undeclared (first use in this function)
     while(i < argc) {
           ^
bat.c:7:11: note: each undeclared identifier is reported only once for each function it appears in
bat.c:13:11: warning: variable ‘states’ set but not used [-Wunused-but-set-variable]
     char *states[] = {
           ^
make: *** [bat] Error 1
devmac@devmac:~/Desktop/LCTHW$

2.) Forget to initialize the second loop's i so that it retains the value from the end of the first loop. Now your second loop might or might not run.
devmac@devmac:~/Desktop/LCTHW$ cat bat.c
#include <stdio.h>

int main(int argc, char *argv[])
{
    // go through each string in argv

    int i = 0;
    while(i < argc) {
        printf("arg %d: %s\n", i, argv[i]);
        i++;
    }

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;

    while(i < num_states) {
        printf("state %d: %s\n", i, states[i]);
        i++;
    }

    return 0;
}
devmac@devmac:~/Desktop/LCTHW$ ./bat
arg 0: ./bat
state 1: Oregon
state 2: Washington
state 3: Texas
devmac@devmac:~/Desktop/LCTHW$ ./bat 123 234 456
arg 0: ./bat
arg 1: 123
arg 2: 234
arg 3: 456
devmac@devmac:~/Desktop/LCTHW$

3.) Forget to do a i++ increment at the end of the loop and you get a "forever loop", one of the dreaded problems of the first decade or two of programming.
devmac@devmac:~/Desktop/LCTHW$ cat bat.c 
#include <stdio.h>

int main(int argc, char *argv[])
{
    // go through each string in argv

    int i = 0;
    while(i < argc) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;
    i = 0;  // watch for this
    while(i < num_states) {
        printf("state %d: %s\n", i, states[i]);
        i++;
    }

    return 0;
}
devmac@devmac:~/Desktop/LCTHW$ 
devmac@devmac:~/Desktop/LCTHW$ ./bat 78
arg 0: ./bat
arg 0: ./bat
arg 0: ./bat
arg 0: ./bat
arg 0: ./bat
arg 0: ./bat
arg 0: ./bat
arg 0: ./bat
arg 0: ./bat
arg 0: ./bat
arg 0: ./bat
arg 0: ./bat
arg 0: ./bat^C
Infine Loop
*/

/*
Extra Credit

1.) Make these loops count backward by using i-- to start at argc and count down to 0. You may have to do some math to make the array indexes work right.
devmac@devmac:~/Desktop/LCTHW$ cat bat.c
#include <stdio.h>

int main(int argc, char *argv[])
{
    // go through each string in argv

    int i = argc - 1;
    while(i >= 0) {
        printf("arg %d: %s\n", i, argv[i]);
        i--;
    }

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;

    i = num_states - 1;
    while(i >= 0) {
        printf("state %d: %s\n", i, states[i]);
        i--;
    }

    return 0;
}
devmac@devmac:~/Desktop/LCTHW$ ./bat 123 234 456 678
arg 4: 678
arg 3: 456
arg 2: 234
arg 1: 123
arg 0: ./bat
state 3: Texas
state 2: Washington
state 1: Oregon
state 0: California
devmac@devmac:~/Desktop/LCTHW$

2.) Use a while loop to copy the values from argv into states.
devmac@devmac:~/Desktop/LCTHW$ cat bat.c
#include <stdio.h>

int main(int argc, char *argv[])
{
    // go through each string in argv

    int i = 0;
    while(i < argc) {
        printf("arg %d: %s\n", i, argv[i]);
        i++;
    }

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;

    i = 0;
    while (i < argc) {
        states[i] = argv[i];
        i++;
    }

    i = 0;  // watch for this
    while(i < num_states) {
        printf("state %d: %s\n", i, states[i]);
        i++;
    }

    return 0;
}
devmac@devmac:~/Desktop/LCTHW$ ./bat ert dfg cvb
arg 0: ./bat
arg 1: ert
arg 2: dfg
arg 3: cvb
state 0: ./bat
state 1: ert
state 2: dfg
state 3: cvb
devmac@devmac:~/Desktop/LCTHW$

3.) Make this copy loop never fail such that if there's too many argv elements it won't put them all into states.
devmac@devmac:~/Desktop/LCTHW$ cat bat.c
#include <stdio.h>

int main(int argc, char *argv[])
{
    // go through each string in argv

    int i = 0;
    while (i < argc) {
        printf("arg %d: %s\n", i, argv[i]);
        i++;
    }

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;

    i = 0;
    int count = num_states > argc ? argc : num_states;
    while (i < count) {
        states[i] = argv[i];
        i++;
    }

    // watch for this
    i = 0;
    while (i < num_states) {
        printf("state %d: %s\n", i, states[i]);
        i++;
    }

    return 0;
}
devmac@devmac:~/Desktop/LCTHW$ ./bat q w e r
arg 0: ./bat
arg 1: q
arg 2: w
arg 3: e
arg 4: r
state 0: ./bat
state 1: q
state 2: w
state 3: e
devmac@devmac:~/Desktop/LCTHW$

4.) Research if you've really copied these strings. The answer may surprise and confuse you though.
The actual strings are not copied
It makes the pointers in *states[] point to a different string in memory
http://stackoverflow.com/questions/9471485/where-is-an-array-of-character-pointers-stored-in-memory
*/
