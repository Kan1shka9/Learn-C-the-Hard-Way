#include<stdio.h>

int main()
{
    int a[5][2] = { {1,2}, {2,3}, {3,4}, {4,5}, {5,6} };
    int i, j;

    for (i = 0 ; i < 5 ; i ++)
    {
        for (j = 0 ; j < 2 ; j++)
        {
            printf("Element[%d][%d] = %d \n", i,j,a[i][j]);
        }
    }
    return 0;
}
