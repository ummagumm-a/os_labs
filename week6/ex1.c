#include <stdlib.h>
#include <stdio.h>

#include "common.h"

void fcfs(process_info* processes, int n)
{
    qsort(processes, n, sizeof(process_info), compare_by_arr_time);
}

int main()
{
    int n;
    printf("N = ");
    scanf("%d", &n);

    process_info* processes = read_processes(n);

    fcfs(processes, n);

    calc_waiting_times(processes, n);
    calc_tats(processes, n);
    calc_completion_times(processes, n);

    print_processes(processes, n);

    return 0;
}

