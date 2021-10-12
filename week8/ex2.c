#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main()
{
    int mb10 = 1000*1024*1024;

    for (int i = 0; i < 10; ++i)
    {
        int* tmp = malloc(mb10);
        memset(tmp, 0, mb10);
        sleep(1);
    }

    return 0;
}

// For ex2: all my pages in browser got disconnected. A lot of swap-out's occur,
// which means that OS evicts pages and loads it to the disk.
// A few swap-in's occur.
// For ex3: amount of virtual memory gradually increases during program execution
