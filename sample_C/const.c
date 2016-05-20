#include<stdio.h>

int main()
{
    const int LENGTH = 10;
    const int WIDTH = 20;
    const char NEWLINE = '\n';
    int area;

    area = LENGTH * WIDTH;
    printf("Area is : %d", area);
    printf("%c", NEWLINE);

    return 0;
}
