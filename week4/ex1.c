#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

// Child process has pid equal to <parent's pid> + 1.
// On each new run of the program processes are 
// assigned new available PIDs in ascenging order.

int main()
{
    pid_t x = fork();
    if (x == 0)
        printf("Hello from child [PID - %d]\n", getpid());
    else
        printf("Hello from child [PID - %d]\n", getpid());

    return 0;
}
