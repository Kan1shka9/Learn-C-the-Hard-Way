#include <stdio.h>

int main(int argc, char *argv[])
{
    int numbers[4] = {0};
    char name[4] = {'a'};

    // first, print them out raw
    printf("numbers: %d %d %d %d\n",
            numbers[0], numbers[1],
            numbers[2], numbers[3]);

    printf("name each: %c %c %c %c\n",
            name[0], name[1],
            name[2], name[3]);

    printf("name: %s\n", name);

    // setup the numbers
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;

    // setup the name
    name[0] = 'Z';
    name[1] = 'e';
    name[2] = 'd';
    name[3] = '\0';

    // then print them out initialized
    printf("numbers: %d %d %d %d\n",
            numbers[0], numbers[1],
            numbers[2], numbers[3]);

    printf("name each: %c %c %c %c\n",
            name[0], name[1],
            name[2], name[3]);

    // print the name like a string
    printf("name: %s\n", name);

    // another way to use name
    char *another = "Zed";

    printf("another: %s\n", another);

    printf("another each: %c %c %c %c\n",
            another[0], another[1],
            another[2], another[3]);

    return 0;
}


//There's also two syntaxes for doing a string: char name[4] = {'a'} on line 6 vs. char *another = "name" on line 44. The first one is less common and the second is what you should use for string literals like this.

/*
Extra Credit

1.) Assign the characters into numbers and then use printf to print them a character at a time. What kind of compiler warnings did you get?
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numbers[4] = {0};

    // setup the numbers
    numbers[0] = 'a';
    numbers[1] = 'b';
    numbers[2] = 'c';
    numbers[3] = 'd';

    // then print them out initialized
    printf("numbers: %c %c %c %c\n", numbers[0], numbers[1], numbers[2], numbers[3]);

    return 0;
}

Output ->
numbers: a b c d

2.) Do the inverse for name, trying to treat it like an array of int and print it out one int at a time. What does Valgrind think of that?
#include <stdio.h>

int main(int argc, char *argv[])
{
    char name[4] = {'a'};

    // setup the name
    name[0] = 100;
    name[1] = 101;
    name[2] = 102;
    name[3] = 103;

    // then print them out initialized
    printf("name each: %d %d %d %d\n", name[0], name[1], name[2], name[3]);

    return 0;
}

Output ->
name each: 100 101 102 103

3.) How many other ways can you print this out?

4.) If an array of characters is 4 bytes long, and an integer is 4 bytes long, then can you treat the whole name array like it's just an integer? How might you accomplish this crazy hack?

5.) Take out a piece of paper and draw out each of these arrays as a row of boxes. Then do the operations you just did on paper to see if you get them right.

6.) Convert name to be in the style of another and see if the code keeps working.
*/
