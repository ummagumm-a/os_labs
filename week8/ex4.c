#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// number of major page faults increases
// it can mean that my program tries to allocate new memory,
// but it doesn't have access to it right away because these pages are on disk
// So it needs to load pages where we previously allocated memory to the disk
// and load required ones to the RAM.
int main()
{
    int mb10 = 100*1024*1024;

    int who = RUSAGE_SELF;
    struct rusage usage;
    int ret;

    for (int i = 0; i < 10; ++i)
    {
       int* tmp = malloc(mb10);
       memset(tmp, 0, mb10);
       ret = getrusage(who, &usage);

       printf("info: %d\t%d\t%d\n", 
            usage.ru_minflt,
            usage.ru_majflt,
            usage.ru_nswap);

       sleep(1);
    }

    return 0;
}

