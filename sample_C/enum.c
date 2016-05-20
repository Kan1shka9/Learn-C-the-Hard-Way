#include<stdio.h>

enum week {
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday
};

int main()
{
    enum week today;
    today = tuesday;
    printf("Today is %d day \n", today);

}
