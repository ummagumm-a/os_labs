#include "tasks.h"
#include <stdio.h>

void print_arr(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    create_linked_list();

    return 0;
}
