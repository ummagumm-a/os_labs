/*
 * common.h
 * Copyright (C) 2021 ummagumma <ummagumma@ummagumma>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef COMMON_H
#define COMMON_H

typedef struct 
{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} process_info;

typedef struct
{
    double av_w_time;
    double av_tat;
} averages;


averages calc_averages(process_info* processes, int n);
void print_processes(process_info* processes, int n);
void calc_tats(process_info* processes, int n);
void calc_completion_times(process_info* processes, int n);
void calc_waiting_times(process_info* processes, int n);
int compare_by_id(const void* p1, const void* p2);
int compare_by_arr_time(const void* p1, const void* p2);
int compare_by_burst_time(const void* p1, const void* p2);
process_info* read_processes(int n);


#endif /* !COMMON_H */
