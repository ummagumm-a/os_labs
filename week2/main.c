#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tasks.h"

int main(int argc, char **argv)
{
    int task_number = 0;

    printf("Write task number --> ");
    scanf("%d", &task_number);

    switch (task_number)
    {
        case 1: 
            task1();
            break;
        case 2: 
            task2();
            break;
        case 3: 
            task3(argv[1]);
            break;
        case 4: 
            task4();
            break;
        default:
            printf("...\n");
            break;
    }

    /*
    int a = 1;
    int b = 2;

    task4(&a, &b);

    printf("%d %d \n", a, b);
    */

    return 0;
}



 
