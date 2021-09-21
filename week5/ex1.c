#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

struct thread_info
{
    pthread_t thread_id;
    int thread_number;
    char* str;
};

void* thread_job(void* args)
{
    struct thread_info* t = (struct thread_info*) args;

    printf("I am a thread #%d.\n", t->thread_number);
    printf("I say: %s", t->str);

    return NULL;
}

int main()
{
    int n = 5;

    struct thread_info* threads;
    threads = malloc(n * sizeof(struct thread_info));
    for (int i = 0; i < n; ++i)
    {
        threads[i].thread_number = i;
        threads[i].str = "blabla\n";
        pthread_create(&threads[i].thread_id, NULL, thread_job, &threads[i]);
        printf("Thread #%d is created\n", i);
        pthread_join(threads[i].thread_id, NULL);
    }

    exit(EXIT_SUCCESS);
}
