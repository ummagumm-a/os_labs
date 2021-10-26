touch ../../week1/file.txt
echo "blabla" >> ../../week1/file.txt

link ../../week1/file.txt _ex2.txt

find -L ~ -samefile ../../week1/file.txt > ex2.txt

find -L ~ -samefile ../../week1/file.txt -exec rm {} \;