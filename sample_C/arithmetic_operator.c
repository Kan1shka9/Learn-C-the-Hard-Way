#include<stdio.h>

main()
{
    int a = 10;
    int b = 30;
    int c;

    c = a + b;
    printf("Line 1: value of c: %d \n", c);
    c = a - b;
    printf("Line 2: value of c: %d \n", c);
    c = a * b;
    printf("Line 3: value of c: %d \n", c);
    c = b / a;
    printf("Line 4: value of c: %d \n", c);
    c = a % b;
    printf("Line 5: value of c: %d \n", c);
    c = a++;
    printf("Line 6: value of c: %d \n", c);
    c = a--;
    printf("Line 7: value of c: %d \n", c);

}
