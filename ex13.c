#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("ERROR: You need one argument.\n");
        // this is how you abort a program
        return 1;
    }

    int i = 0;
    for(i = 0; argv[1][i] != '\0'; i++) {
        char letter = argv[1][i];

        switch(letter) {
            case 'a':
            case 'A':
                printf("%d: 'A'\n", i);
                break;

            case 'e':
            case 'E':
                printf("%d: 'E'\n", i);
                break;

            case 'i':
            case 'I':
                printf("%d: 'I'\n", i);
                break;

            case 'o':
            case 'O':
                printf("%d: 'O'\n", i);
                break;

            case 'u':
            case 'U':
                printf("%d: 'U'\n", i);
                break;

            case 'y':
            case 'Y':
                if(i > 2) {
                    // it's only sometimes Y
                    printf("%d: 'Y'\n", i);
                }
                break;

            default:
                printf("%d: %c is not a vowel\n", i, letter);
        }
    }

    return 0;
}

/*
How To Break It

1.) Forget a break and it'll run two or more blocks of code you don't want it to run.
devmac@devmac:~/Desktop/LCTHW$ cat bat.c
#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("ERROR: You need one argument.\n");
        // this is how you abort a program
        return 1;
    }

    int i = 0;
    for(i = 0; argv[1][i] != '\0'; i++) {
        char letter = argv[1][i];

        switch(letter) {
            case 'a':
            case 'A':
                printf("%d: 'A'\n", i);

            case 'e':
            case 'E':
                printf("%d: 'E'\n", i);

            case 'i':
            case 'I':
                printf("%d: 'I'\n", i);

            case 'o':
            case 'O':
                printf("%d: 'O'\n", i);

            case 'u':
            case 'U':
                printf("%d: 'U'\n", i);

            case 'y':
            case 'Y':
                if(i > 2) {
                    // it's only sometimes Y
                    printf("%d: 'Y'\n", i);
                }

            default:
                printf("%d: %c is not a vowel\n", i, letter);
        }
    }

    return 0;
}
devmac@devmac:~/Desktop/LCTHW$ ./bat kanishka
0: k is not a vowel
1: 'A'
1: 'E'
1: 'I'
1: 'O'
1: 'U'
1: a is not a vowel
2: n is not a vowel
3: 'I'
3: 'O'
3: 'U'
3: 'Y'
3: i is not a vowel
4: s is not a vowel
5: h is not a vowel
6: k is not a vowel
7: 'A'
7: 'E'
7: 'I'
7: 'O'
7: 'U'
7: 'Y'
7: a is not a vowel
devmac@devmac:~/Desktop/LCTHW$

2.) Forget a default and have it silently ignore values you forgot.
devmac@devmac:~/Desktop/LCTHW$ cat bat.c 
#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("ERROR: You need one argument.\n");
        // this is how you abort a program
        return 1;
    }

    int i = 0;
    for(i = 0; argv[1][i] != '\0'; i++) {
        char letter = argv[1][i];

        switch(letter) {
            case 'a':
            case 'A':
                printf("%d: 'A'\n", i);
                break;

            case 'e':
            case 'E':
                printf("%d: 'E'\n", i);
                break;

            case 'i':
            case 'I':
                printf("%d: 'I'\n", i);
                break;

            case 'o':
            case 'O':
                printf("%d: 'O'\n", i);
                break;

            case 'u':
            case 'U':
                printf("%d: 'U'\n", i);
                break;

            case 'y':
            case 'Y':
                if(i > 2) {
                    // it's only sometimes Y
                    printf("%d: 'Y'\n", i);
                }
                break;

        }
    }

    return 0;
}
devmac@devmac:~/Desktop/LCTHW$ ./bat kanishka
1: 'A'
3: 'I'
7: 'A'
devmac@devmac:~/Desktop/LCTHW$

3.) Accidentally put in variable into the switch that evaluates to something unexpected, like an int that becomes weird values.

4.) Use uninitialized values in the switch.
*/

/*
1.) Write another program that uses math on the letter to convert it to lowercase, and then remove all the extraneous uppercase letters in the switch.
#include <stdio.h>

char toLowerCase(char letter)
{
    if (letter >= 97 && letter <= 122) {
        return letter;
    } else if (letter >= 65 && letter <=90) {
        return letter + 32;
    } else {
        return letter;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("ERROR: You need one argument.\n");

        // this is how you abort a program
        return 1;
    }

    int i = 0;
    for (i = 0; argv[1][i] != '\0'; i++) {
        char letter = argv[1][i];
        char lowerCaseLetter = toLowerCase(letter);

        switch (lowerCaseLetter) {
            case 'a':
                printf("%d: 'A'\n", i);
                break;
            case 'e':
                printf("%d: 'E'\n", i);
                break;
            case 'i':
                printf("%d: 'I'\n", i);
                break;
            case 'o':
                printf("%d: 'O'\n", i);
                break;
            case 'u':
                printf("%d: 'U'\n", i);
                break;
            case 'y':
                if (i > 2) {
                    // it's only sometimes Y
                    printf("%d: 'Y'\n", i);
                }

                break;
            default:
                printf("%d: %c is not a vowel\n", i, letter);
        }
    }

    return 0;
}

2.) Use the ',' (comma) to initialize letter in the for-loop.
devmac@devmac:~/Desktop/LCTHW$ cat bat.c 
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("ERROR: You need one argument.\n");

        // this is how you abort a program
        return 1;
    }

    int i = 0;
    char letter = 0;
    for (i = 0; letter = argv[1][i], letter != '\0'; i++) {
        switch (letter) {
            case 'a':
            case 'A':
                printf("%d: 'A'\n", i);
                break;
            case 'e':
            case 'E':
                printf("%d: 'E'\n", i);
                break;
            case 'i':
            case 'I':
                printf("%d: 'I'\n", i);
                break;
            case 'o':
            case 'O':
                printf("%d: 'O'\n", i);
                break;
            case 'u':
            case 'U':
                printf("%d: 'U'\n", i);
                break;
            case 'y':
            case 'Y':
                if (i > 2) {
                    // it's only sometimes Y
                    printf("%d: 'Y'\n", i);
                }

                break;
            default:
                printf("%d: %c is not a vowel\n", i, letter);
        }
    }

    return 0;
}
devmac@devmac:~/Desktop/LCTHW$ ./bat kanishka
0: k is not a vowel
1: 'A'
2: n is not a vowel
3: 'I'
4: s is not a vowel
5: h is not a vowel
6: k is not a vowel
7: 'A'
devmac@devmac:~/Desktop/LCTHW$ 

3.) Make it handle all of the arguments you pass it with yet another for-loop.
devmac@devmac:~/Desktop/LCTHW$ cat bat.c 
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 1) {
        printf("ERROR: You have no argument.\n");

        // this is how you abort a program
        return 1;
    }

    int j = 0;
    int i = 0;
    char letter = 0;
    char *arr;

    for (j = 1; j < argc; j++) {
        arr = argv[j];
        printf("Argument %d: %s\n", j, arr);

        for (i = 0; letter = arr[i], letter != '\0'; i++) {
            switch (letter) {
                case 'a':
                case 'A':
                    printf("%d: 'A'\n", i);
                    break;
                case 'e':
                case 'E':
                    printf("%d: 'E'\n", i);
                    break;
                case 'i':
                case 'I':
                    printf("%d: 'I'\n", i);
                    break;
                case 'o':
                case 'O':
                    printf("%d: 'O'\n", i);
                    break;
                case 'u':
                case 'U':
                    printf("%d: 'U'\n", i);
                    break;
                case 'y':
                case 'Y':
                    if (i > 2) {
                        // it's only sometimes Y
                        printf("%d: 'Y'\n", i);
                    }

                    break;
                default:
                    printf("%d: %c is not a vowel\n", i, letter);
            }
        }
    }

    return 0;
}
devmac@devmac:~/Desktop/LCTHW$ ./bat kanishka
Argument 1: kanishka
0: k is not a vowel
1: 'A'
2: n is not a vowel
3: 'I'
4: s is not a vowel
5: h is not a vowel
6: k is not a vowel
7: 'A'
devmac@devmac:~/Desktop/LCTHW$

4.) Convert this switch-statement to an if-statement. Which do you like better?
devmac@devmac:~/Desktop/LCTHW$ cat bat.c 
#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("ERROR: You need one argument.\n");
        // this is how you abort a program
        return 1;
    }

    int i = 0;
    for(i = 0; argv[1][i] != '\0'; i++) {
        char letter = argv[1][i];

	if (letter == 'a' || letter == 'A') {
		printf("%d: 'A'\n", i);
	} else if (letter == 'e' || letter == 'E') {
		printf("%d: 'E'\n", i);
	} else if (letter == 'i' || letter == 'I') {
		printf("%d: 'I'\n", i);
	} else if (letter == 'o' || letter == 'O') {
		printf("%d: 'O'\n", i);
	} else if (letter == 'u' || letter == 'U') {
                printf("%d: 'U'\n", i);
	} else if (letter == 'y' || letter == 'Y') {
                if(i > 2) {
                    // it's only sometimes Y
                    printf("%d: 'Y'\n", i);
                }
	} else {
                printf("%d: %c is not a vowel\n", i, letter);
        }
    }

    return 0;
}
devmac@devmac:~/Desktop/LCTHW$ ./bat Kanishka
0: K is not a vowel
1: 'A'
2: n is not a vowel
3: 'I'
4: s is not a vowel
5: h is not a vowel
6: k is not a vowel
7: 'A'
devmac@devmac:~/Desktop/LCTHW$

5.) In the case for 'Y' I have the break outside the if-statement. What's the impact of this and what happens if you move it inside the if-statement. Prove to yourself that you're right.
Case 1 -> Break inside the if statement
devmac@devmac:~/Desktop/LCTHW$ cat bat.c 
#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("ERROR: You need one argument.\n");
        // this is how you abort a program
        return 1;
    }

    int i = 0;
    for(i = 0; argv[1][i] != '\0'; i++) {
        char letter = argv[1][i];

        switch(letter) {
            case 'a':
            case 'A':
                printf("%d: 'A'\n", i);
                break;

            case 'e':
            case 'E':
                printf("%d: 'E'\n", i);
                break;

            case 'i':
            case 'I':
                printf("%d: 'I'\n", i);
                break;

            case 'o':
            case 'O':
                printf("%d: 'O'\n", i);
                break;

            case 'u':
            case 'U':
                printf("%d: 'U'\n", i);
                break;

            case 'y':
            case 'Y':
                if(i > 2) {
                    // it's only sometimes Y
                    printf("%d: 'Y'\n", i);
		    break;
                }

            default:
                printf("%d: %c is not a vowel\n", i, letter);
        }
    }

    return 0;
}
devmac@devmac:~/Desktop/LCTHW$ ./bat yak
0: y is not a vowel
1: 'A'
2: k is not a vowel
devmac@devmac:~/Desktop/LCTHW$ 

Case 2 -> Break outside the if statement
devmac@devmac:~/Desktop/LCTHW$ cat bat.c 
#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("ERROR: You need one argument.\n");
        // this is how you abort a program
        return 1;
    }

    int i = 0;
    for(i = 0; argv[1][i] != '\0'; i++) {
        char letter = argv[1][i];

        switch(letter) {
            case 'a':
            case 'A':
                printf("%d: 'A'\n", i);
                break;

            case 'e':
            case 'E':
                printf("%d: 'E'\n", i);
                break;

            case 'i':
            case 'I':
                printf("%d: 'I'\n", i);
                break;

            case 'o':
            case 'O':
                printf("%d: 'O'\n", i);
                break;

            case 'u':
            case 'U':
                printf("%d: 'U'\n", i);
                break;

            case 'y':
            case 'Y':
                if(i > 2) {
                    // it's only sometimes Y
                    printf("%d: 'Y'\n", i);
                }
		break;

            default:
                printf("%d: %c is not a vowel\n", i, letter);
        }
    }

    return 0;
}
devmac@devmac:~/Desktop/LCTHW$ ./bat yak
1: 'A'
2: k is not a vowel
devmac@devmac:~/Desktop/LCTHW$ 
*/
