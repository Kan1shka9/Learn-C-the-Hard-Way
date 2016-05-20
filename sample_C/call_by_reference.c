// Call by reference :-
// Method of passing arguments to a function copies the address of an argument into the formal parameter.
// Inside the function, the address is used to access the actual argument used in the call. This means that changes made to the parameter affect the passed argument.
// To pass the value by reference, argument pointers are passed to the functions just like any other value

#include<stdio.h>

void swap(int *x, int *y);

int main()
{
    int a = 100;
    int b = 200;

    printf("Value of a before swapping: %d \n", a);
    printf("Value of b before swapping: %d \n", b);

    swap(&a, &b);

    printf("Value of a after swapping: %d \n", a);
    printf("Value of b after swapping: %d \n", b);

    return 0;
}

void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;

    return;
}
/*
Output :-
dev@box:~/Desktop/C$ ./call_by_reference
Value of a before swapping: 100
Value of b before swapping: 200
Value of a after swapping: 200
Value of b after swapping: 100
*/
