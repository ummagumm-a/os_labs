#include "tasks.h"
#include <stdio.h>

#define swap(x, y) { int tmp = *x; *x = *y; *y = tmp; }

int* bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (arr[i] < arr[j]) 
                swap (&arr[i], &arr[j]);
        }
    }

    return arr;
}

int main()
{
    int arr[5] = { 2, 5, 1, 6, 3 };
    bubble_sort(arr, 5);

    for (int i = 0; i < 5; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
