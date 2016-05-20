#include<stdio.h>

/*function declaration*/
void fun(void);

static int count = 5; /*Global variable declaration*/

main()
{
    while(count--)
    {
        fun();
    }
    return 0;
}
/*function definition*/
void fun(void)
{
    static int i = 5; /*local static variable*/
    i++;

    printf("i is %d and count is %d \n", i,count);

}
