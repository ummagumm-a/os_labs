for ((i=1;i<=$1;i++));
do
    if [ -s ex2.txt ]
    then
        tag=$( tail -n 1 ex2.txt )
        next=`expr $tag + 1`
        echo $next >> ex2.txt
    else
        touch ex2.txt
        echo 1 >> ex2.txt
    fi
done

