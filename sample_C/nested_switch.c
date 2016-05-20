#include<stdio.h>

int main()
{
    int a = 100;
    int b = 200;

    switch(a)
    {
        case 100 :
            printf("This is a part of the outer switch \n");
            break;
            switch(b)
            {
            case 200 :
                printf("This is a part of the inner switch \n");
                break;
            }
    }
    printf("Exact value of a : %d \n", a);
    printf("Exact value of b : %d \n", b);

    return 0;
}



