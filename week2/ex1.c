#include <float.h>
#include <limits.h>

#include "tasks.h"

void task1()
{
    int i = INT_MAX;
    float f = FLT_MAX;
    double d = DBL_MAX;

    printf("Int size is %d and value is %d \n", sizeof(i), i);
    printf("Float size is %d and value is %f \n", sizeof(f), f);
    printf("Double size is %d and value is %lf \n", sizeof(d), d);
}
