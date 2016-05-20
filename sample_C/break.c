#include<stdio.h>

int main()
{
    int i = 10;

    while (i < 20)
    {
        printf("Value of i is %d \n", i);
        i++;
        if (i > 15)
        {
            break;
        }
    }
}

