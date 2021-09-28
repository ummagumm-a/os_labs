#include <stdlib.h>
#include <stdio.h>

#include "common.h"

process_info* shortest_job_next(process_info* processes, int n)
{
    qsort(processes, n, sizeof(process_info), compare_by_arr_time);

    process_info* new_sequence = (process_info*) malloc(n * sizeof(new_sequence));
    process_info* ready = (process_info*) malloc(n * sizeof(new_sequence));

    int i = 0;
    int j = 0;
    int in_process = 0;
    int ind = 0;

    int n_ready = 0;

    while (ind != n)
    {
        while (processes[j].arrival_time <= i && j < n)
            ready[n_ready++] = processes[j++];

        
        qsort(ready, n_ready, sizeof(process_info), compare_by_burst_time);

        if (in_process == 0 && n_ready != 0)
        {
            new_sequence[ind++] = ready[0];
            ready++;
            n_ready--;
        }
            
        i++;
        if (in_process != 0)
            in_process--;
    }

    return new_sequence;
}

int main()
{
    int n;
    printf("N = ");
    scanf("%d", &n);

    process_info* processes = read_processes(n);

    process_info* result = (process_info*) malloc(n * sizeof(process_info));
    result = shortest_job_next(processes, n);

    calc_waiting_times(result, n);
    calc_tats(result, n);
    calc_completion_times(result, n);

    print_processes(result, n);

    return 0;
}

