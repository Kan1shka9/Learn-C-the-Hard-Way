#include <stdio.h>

int main(int argc, char *argv[])
{
    int areas[] = {10, 12, 13, 14, 20};
    char name[] = "Zed";
    char full_name[] = {
        'Z', 'e', 'd',
         ' ', 'A', '.', ' ',
         'S', 'h', 'a', 'w', '\0'
    };

    // WARNING: On some systems you may have to change the
    // %ld in this code to a %u since it will use unsigned ints
    printf("The size of an int: %ld\n", sizeof(int));
    printf("The size of areas (int[]): %ld\n",
            sizeof(areas));
    printf("The number of ints in areas: %ld\n",
            sizeof(areas) / sizeof(int));
    printf("The first area is %d, the 2nd %d.\n",
            areas[0], areas[1]);

    printf("The size of a char: %ld\n", sizeof(char));
    printf("The size of name (char[]): %ld\n",
            sizeof(name));
    printf("The number of chars: %ld\n",
            sizeof(name) / sizeof(char));

    printf("The size of full_name (char[]): %ld\n",
            sizeof(full_name));
    printf("The number of chars: %ld\n",
            sizeof(full_name) / sizeof(char));

    printf("name=\"%s\" and full_name=\"%s\"\n",
            name, full_name);

    return 0;
}

/*
Extra Credit
1.) Try assigning to elements in the areas array with areas[0] = 100; and similar.
2.) Try assigning to elements of name and full_name.
3.) Try setting one element of areas to a character from name.
#include <stdio.h>

int main(int argc, char *argv[])
{
int areas[] = {10, 12, 13, 14, 20};
    char name[] = "Zed";
    char full_name[] = {
        'Z', 'e', 'd',
         ' ', 'A', '.', ' ',
         'S', 'h', 'a', 'w', '\0'
    };

// Try assigning to elements in the areas array with areas[0] = 100; and similar.
areas[0] = 100;
areas[1] = 200;
printf("Now the first area is %d, the 2nd %d.\n", areas[0], areas[1]);

// Try assigning to elements of name and full_name.
name[0] = 'K';
full_name[0] = 'K';
printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);

// Try setting one element of areas to a character from name.
areas[0] = name[0];
printf("Now the first area is %d.\n", areas[0]);

return 0;
}

Output ->
Now the first area is 100, the 2nd 200.
name="Ked" and full_name="Ked A. Shaw"
Now the first area is 75.

4.) Go search online for the different sizes used for integers on different CPUs.
http://stackoverflow.com/questions/2331751/does-the-size-of-an-int-depend-on-the-compiler-and-or-processor
*/

