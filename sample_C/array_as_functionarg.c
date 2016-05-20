#include<stdio.h>

double getAverage(int arr[], int size)
{
    int i;
    double sum;
    double avg;

    for (i = 0 ; i < size ; i++)
    {
        sum += arr[i];
    }

    avg = sum/size;

    return avg;
}
int main()
{
    int balance[5] = {1000, 56, 45, 67, 89};
    double avg;

    avg = getAverage(balance, 5);

    printf("Average is %f \n", avg);

    return 0;

}
