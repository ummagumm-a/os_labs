#include <sys/types.h>
#include <unistd.h>

int main()
{
    for (int i = 0; i < 5; ++i)
    {
        fork();
        sleep(2);
    }

    return 0;
}
