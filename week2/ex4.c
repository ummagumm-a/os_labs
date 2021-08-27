#include "tasks.h"

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void task4()
{
    int aInt = 0;
    int bInt = 0;

    printf("Enter two numbers --> ");
    scanf("%d %d", &aInt, &bInt);

    swap(&aInt, &bInt);

    printf("%d %d \n", aInt, bInt);
}   
