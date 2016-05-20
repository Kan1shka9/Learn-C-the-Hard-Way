#include <stdio.h>

int main(int argc, char *argv[])
{
    int distance = 100;
    float power = 2.345f;
    double super_power = 56789.4532;
    char initial = 'A';
    char first_name[] = "Zed";
    char last_name[] = "Shaw";

    printf("You are %d miles away.\n", distance);
    printf("You have %f levels of power.\n", power);
    printf("You have %f awesome super powers.\n", super_power);
    printf("I have an initial %c.\n", initial);
    printf("I have a first name %s.\n", first_name);
    printf("I have a last name %s.\n", last_name);
    printf("My whole name is %s %c. %s.\n",
            initial, first_name, last_name);

    return 0;
}

/*
Extra Credit
1.) Come up with other ways to break this C code by changing the printf, then fix them.

2.) Go search for "printf formats" and try using a few of the more exotic ones.
#include <stdio.h>

int main(int argc, char *argv[])
{
    int hex_val = 80;

    printf("The hex value is : %x \n", hex_val);

    return 0;
}

Output ->
The hex value is : 50

3.) Research how many different ways you can write a number. Try octal, hexadecimal, and others you can find.
#include <stdio.h>

int main(int argc, char *argv[])
{
    int val = 80;

    printf("The hex value is : %x \n", val);
    printf("The unsigned decimal : %u \n", val);
    printf("The int unsigned octal value : %o \n", val);
    printf("The float value : %f \n", val);
    printf("The exponential value : %e \n", val);

    return 0;
}

Output ->
The hex value is : 50
The unsigned decimal : 80
The int unsigned octal value : 120
The float value : -0.559736
The exponential value : -5.597363e-01

4.) Try printing an empty string that's just "".
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("%s", "");

    return 0;
}
*/
