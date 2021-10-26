#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main()
{
    struct dirent* dir;
    DIR* d = opendir("./tmp/");

    if (d)
    {
        printf("File --- Hard Links\n");
        while ((dir = readdir(d)) != NULL)
        {
            struct stat st;
            char dest[512] = "./tmp/";
            strcat(dest, dir->d_name);
            stat(dest, &st);

            struct dirent* link;
            if (st.st_nlink >= 2 && strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0)
            {
                DIR* d2 = opendir("tmp");
                printf("%s\t", dir->d_name);

                while((link = readdir(d2)) != NULL)
                    if (link->d_ino == dir->d_ino)
                        printf("%s ", link->d_name);

                printf("\n");
                closedir(d2);
            }
        }
        closedir(d);
    }
    else
        printf("file problem\n");

    return 0;
}