#include <stdlib.h>
#include <stdio.h>

#include "common.h"

int* calc_rem_ts(process_info* processes, int n)
{
    int* rem_ts = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i)
        rem_ts[i] = processes[i].burst_time;

    return rem_ts;
}

void round_robin(process_info* processes, int n, int quantum)
{
    qsort(processes, n, sizeof(process_info), compare_by_arr_time);

    int* rem_ts = calc_rem_ts(processes, n);

    int timer = processes[0].arrival_time;
    int some_left = 1;
    while (some_left)
    { 
        some_left = 0;
        int was_incr = 0;
        for (int i = 0; i < n; i++)
        {
            if (rem_ts[i] > 0) some_left = 1;

            if (processes[i].arrival_time <= timer && rem_ts[i] > 0)
            {
                if (rem_ts[i] > quantum)
                {
                    timer += quantum;
                    rem_ts[i] -= quantum;
                }
                else
                {
                    timer += rem_ts[i];
                    rem_ts[i] = 0;
                    processes[i].waiting_time = timer 
                        - processes[i].burst_time 
                        - processes[i].arrival_time;
                }
                was_incr = 1;
            }
        }
        if (!was_incr) timer++;
    }
}

int main()
{
    int n;
    printf("N = ");
    scanf("%d", &n);

    int quantum;
    printf("Quantum = ");
    scanf("%d", &quantum);

    process_info* processes = read_processes(n);

    round_robin(processes, n, quantum);

    calc_tats(processes, n);
    calc_completion_times(processes, n);

    print_processes(processes, n);

    return 0;
}
