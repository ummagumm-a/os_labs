#include <stdlib.h>

#include "tasks.h"

int strToInt(char str[])
{
    int n;

    sscanf(str, "%d", &n);

    return n;
}

void task3(char str[])
{
    int n = strToInt(str);

    for (int i = 0; i < n; ++i)
    {
        for (int j = -n + 1; j < n; ++j)
        {
            if (abs(j) <= i)
            {
                putchar('*');
            }
            else
            {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}
