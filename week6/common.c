#include <stdlib.h>
#include <stdio.h>

#include "common.h"

averages calc_averages(process_info* processes, int n)
{
    averages av;
    av.av_w_time = 0;
    av.av_tat = 0;

    for (int i = 0; i < n; ++i)
    {
        av.av_w_time += (double) processes[i].waiting_time;
        av.av_tat += (double) processes[i].turnaround_time;
    }

    av.av_w_time /= (double) n;
    av.av_tat /= (double) n;

    return av;
}

void print_processes(process_info* processes, int n)
{

   printf("STATISTICS\n");
   printf("=====================================================================\n");
   printf("Process id\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
   for (int i = 0; i < n; ++i)
       printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               processes[i].pid,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].completion_time,
               processes[i].waiting_time,
               processes[i].turnaround_time);

   averages av = calc_averages(processes, n);
   printf("AVERAGE:\t\t\t\t\t\t\t%lf\t\t%lf\n", av.av_w_time, av.av_tat);
   printf("=====================================================================\n");
}

void calc_tats(process_info* processes, int n)
{
    for (int i = 0; i < n; ++i)
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
}

void calc_completion_times(process_info* processes, int n)
{
    for (int i = 0; i < n; ++i)
        processes[i].completion_time = processes[i].arrival_time + processes[i].turnaround_time;
}

void calc_waiting_times(process_info* processes, int n)
{
    processes[0].waiting_time = 0;
    for (int i = 1; i < n; ++i)
    {
        processes[i].waiting_time 
            = processes[i - 1].waiting_time 
            + processes[i - 1].burst_time
            + processes[i - 1].arrival_time 
            - processes[i].arrival_time;
        if (processes[i].waiting_time < 0)
            processes[i].waiting_time = 0;
    }
}

int compare_by_id(const void* p1, const void* p2)
{
    process_info arg1 = *(const process_info*)p1;
    process_info arg2 = *(const process_info*)p2;

    if (arg1.pid < arg2.pid) return -1;
    if (arg1.pid > arg2.pid) return 1;

    return 0;
}

int compare_by_arr_time(const void* p1, const void* p2)
{
    process_info arg1 = *(const process_info*)p1;
    process_info arg2 = *(const process_info*)p2;

    if (arg1.arrival_time < arg2.arrival_time) return -1;
    if (arg1.arrival_time > arg2.arrival_time) return 1;

    return 0;
}

int compare_by_burst_time(const void* p1, const void* p2)
{
    process_info arg1 = *(const process_info*)p1;
    process_info arg2 = *(const process_info*)p2;

    if (arg1.burst_time < arg2.burst_time) return -1;
    if (arg1.burst_time > arg2.burst_time) return 1;

    return 0;
}

process_info* read_processes(int n)
{
    process_info* processes = (process_info*) malloc(n * sizeof(process_info));
    int ar_t, b_t, pid;
    for (int i = 0; i < n; ++i)
    {
        printf("=============================================================\n");
        printf("Arrival time: ");
        scanf("%d", &ar_t);
        printf("Burst time: ");
        scanf("%d", &b_t);
        printf("=============================================================\n");

        process_info new_p;
        new_p.arrival_time = ar_t;
        new_p.burst_time = b_t;
        new_p.pid = i + 1;

        processes[i] = new_p;
    }

    return processes;
}

