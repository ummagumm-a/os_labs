#include "tasks.h"
#include <string.h>

void task2()
{
    char str[50];

    printf("Enter a string --> ");
    scanf("%s", str);

    int strL = strlen(str);

    for (int i = 0; i < strL; ++i)
    {
        putchar(str[strL - i - 1]);
    }
    putchar('\n');
}
