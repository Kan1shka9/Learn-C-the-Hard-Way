#include<stdio.h>

int a = 10;

int main()
{
    int a = 20;
    int b = 30;
    int c = 0;

    printf("Value of a in main() function is %d \n", a);
    c = sum(a,b);
    printf("Value of c in main() function is %d \n", c);
    return 0;

}

int sum(int x, int y)
{
    printf("Value of a in sum() is %d \n", x);
    printf("Value of b in sum() is %d \n", y);

    return x + y;

}
