#include<stdio.h>

int main()
{
    int p = 20;
    int *i;

    i = &p;

    printf("Address of p is %x \n", &p);

    printf("Address of i is %x \n", i);

    printf("Value stored in *i is %d \n", *i);

    return 0;

}
