#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    if(argc == 1) {
        printf("You only have one argument. You suck.\n");
    } else if(argc > 1 && argc < 4) {
        printf("Here's your arguments:\n");

        for(i = 0; i < argc; i++) {
            printf("%s ", argv[i]);
        }
        printf("\n");
    } else {
        printf("You have too many arguments. You suck.\n");
    }

    return 0;
}

/*
How To Break It

1.) Remove the else at the end and it won't catch the edge case.
devmac@devmac:~/Desktop/LCTHW$ cat g.c
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    if(argc == 1) {
        printf("You only have one argument. You suck.\n");
    } else if(argc > 1 && argc < 4) {
        printf("Here's your arguments:\n");

        for(i = 0; i < argc; i++) {
            printf("%s ", argv[i]);
        }
        printf("\n");
    }

    return 0;
}
devmac@devmac:~/Desktop/LCTHW$ ./g a s d f g h j k
devmac@devmac:~/Desktop/LCTHW$ ./g
You only have one argument. You suck.
devmac@devmac:~/Desktop/LCTHW$ ./g w f
Here's your arguments:
./g w f
devmac@devmac:~/Desktop/LCTHW$

2.) Change the && to a || so you get an "or" instead of "and" test and see how that works.
devmac@devmac:~/Desktop/LCTHW$ cat g.c
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    if(argc == 1) {
        printf("You only have one argument. You suck.\n");
    } else if(argc > 1 || argc < 4) {
        printf("Here's your arguments:\n");

        for(i = 0; i < argc; i++) {
            printf("%s ", argv[i]);
        }
        printf("\n");
    } else {
        printf("You have too many arguments. You suck.\n");
    }

    return 0;
}
devmac@devmac:~/Desktop/LCTHW$ ./g
You only have one argument. You suck.
devmac@devmac:~/Desktop/LCTHW$ ./g 1 2
Here's your arguments:
./g 1 2
devmac@devmac:~/Desktop/LCTHW$ ./g 1 2 3 4 5 6
Here's your arguments:
./g 1 2 3 4 5 6
devmac@devmac:~/Desktop/LCTHW$
*/

/*
Extra Credit

1.) You were briefly introduced to &&, which does an "and" comparison, so go research online the different "boolean operators".
http://www.tutorialspoint.com/cprogramming/c_logical_operators.htm

2.) Write a few more test cases for this program to see what you can come up with.

3.) Go back to Exercises 10 and 11, and use if-statements to make the loops exit early. You'll need the break statement to do that. Go read about it.
Exercise 11
devmac@devmac:~/Desktop/LCTHW$ cat g.c
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

    // watch for this
    i = 0;
    while (i < num_states) {
        printf("state %d: %s\n", i, states[i]);
        i++;

        if (i == 2) {
            break;
        }
    }

    return 0;
}
devmac@devmac:~/Desktop/LCTHW$ ./g
arg 0: ./g
state 0: California
state 1: Oregon
devmac@devmac:~/Desktop/LCTHW$ ./g 1 2 3
arg 0: ./g
arg 1: 1
arg 2: 2
arg 3: 3
state 0: California
state 1: Oregon
devmac@devmac:~/Desktop/LCTHW$

Exercise 10
devmac@devmac:~/Desktop/LCTHW$ cat g.c
#include <stdio.h>

int main (int argc, char *argv[])
{
    int i = 0;

    // go through each string in argv
    // why am I skipping argv[0]?
    for (i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;

    for (i = 0; i < num_states; i++) {
        if (i == 2) {
            break;
        }

        printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}
devmac@devmac:~/Desktop/LCTHW$ ./g
state 0: California
state 1: Oregon
devmac@devmac:~/Desktop/LCTHW$ ./g  1 2 3
arg 1: 1
arg 2: 2
arg 3: 3
state 0: California
state 1: Oregon
devmac@devmac:~/Desktop/LCTHW$

4.) Is the first test really saying the right thing? To you the "first argument" isn't the same first argument a user entered. Fix it.
devmac@devmac:~/Desktop/LCTHW$ cat g.c
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    if(argc == 1) {
        printf("You do not have any arguments\n");
    } else if(argc == 2){
        printf("You have one argument\n");
    } else if(argc > 1 && argc < 4) {
        printf("Here's your arguments:\n");

        for(i = 0; i < argc; i++) {
            printf("%s ", argv[i]);
        }
        printf("\n");
    } else {
        printf("You have too many arguments. You suck.\n");
    }

    return 0;
}
devmac@devmac:~/Desktop/LCTHW$
devmac@devmac:~/Desktop/LCTHW$ ./g
You do not have any arguments
devmac@devmac:~/Desktop/LCTHW$ ./g 1
You have one argument
devmac@devmac:~/Desktop/LCTHW$ ./g 1 2
Here's your arguments:
./g 1 2
devmac@devmac:~/Desktop/LCTHW$ ./g 1 2 3
You have too many arguments. You suck.
*/
