gcc ex2.c -o ex2
./ex2 & 
ex2_pid=$!
top -p $ex2_pid
