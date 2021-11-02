#include <stdio.h>
#include <dirent.h>

int main()
{
    DIR* dir;
    struct dirent* dirent_;
    dir = opendir("/");

    dirent_ = readdir(dir);
    while (dirent_ != NULL)
    {
        printf("%s\n", dirent_->d_name);
        dirent_ = readdir(dir);
    }
    closedir(dir);

    return 0;
}


