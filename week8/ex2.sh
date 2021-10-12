gcc ex2.c -o ex2
./ex2 & 
ex2_pid=$!
vmstat 1 $ex2_pid
