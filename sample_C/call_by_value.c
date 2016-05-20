//Call by value :-
//Method of passing arguments to a function copies the actual value of an argument into the formal parameter of the function.
//In this case, changes made to the parameter inside the function have no effect on the argument.
//By default, C programming language uses call by value method to pass arguments. In general, this means that code within a function cannot alter the arguments used to call the function.

#include<stdio.h>

void swap(int x, int y);

int main()
{
    int a = 100;
    int b = 200;

    printf("Value of a before swapping: %d \n", a);
    printf("Value of b before swapping: %d \n", b);

    swap(a, b);

    printf("Value of a after swapping: %d \n", a);
    printf("Value of b after swapping: %d \n", b);

    return 0;
}

void swap(int x, int y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;

    return;
}
/*
Output :-
dev@box:~/Desktop/C$ ./call_by_value
Value of a before swapping: 100
Value of b before swapping: 200
Value of a after swapping: 100
Value of b after swapping: 200
No change to the values of a and b
*/
