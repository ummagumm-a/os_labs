for i in {1..10}
do
    echo "$i's time"
    gcc ex1.c -o ex1 && ./ex1
done
