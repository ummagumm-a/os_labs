gcc ex2.c -o ex2
./ex2 & 
ex2_pid=$!
for i in {1..5}
do
    pstree $ex2_pid 
    sleep 2
done


