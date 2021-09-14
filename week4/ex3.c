#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char command[20];

    while (scanf("%s", command), strcmp(command, "exit") != 0)
    {
        system(command);
    }

    return 0;
}
