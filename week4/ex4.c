#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


char** tokenize(size_t* size)
{
    char* inp = NULL;
    size_t len = 0;
    char** tokens = malloc(10 * sizeof(char*));

    getline(&inp, &len, stdin);
    inp[strlen(inp) - 1] = '\000';
    char* token = strtok(inp, " ");

    int i = 0;
    while (token != NULL)
    {
        tokens[i++] = strdup(token);
        token = strtok(NULL, " ");
    }

    tokens[i] = (char*) NULL;
    *size = i;

    return tokens;
}

int main()
{
    size_t n_tokens = 0;
    char** argv_p = tokenize(&n_tokens);
    char* const argv[3] = { "ls", "-la", NULL };
    char* const *argv_t ;

    for (int i = 0; i < n_tokens; ++i)
    {
        printf(argv_p[i]);
    }
    int pdi = fork();
    if (pdi == 0) execvp(argv_p[0], argv_p);
    else waitpid(pdi, NULL, 0);



//    execvp(argv_p[0], argv_p);

//    char command[20];
//
//    char* const argv[3] = { "ls", "-la", NULL };
//
//    while (scanf("%s", command), strcmp(command, "exit") != 0)
//    {
//        int pdi = fork();
//    
//        if (pdi == 0)
//            execvp(argv[0], argv);
//    }

    return 0;
}
