sudo chmod 777 lofsdisk
sudo touch lofsdisk/file1 lofsdisk/file2
sudo chmod 777 lofsdisk/file1
sudo chmod 777 lofsdisk/file2
sudo echo "Viacheslav" >> lofsdisk/file1
sudo echo "Sinii" >> lofsdisk/file2
sudo mkdir lofsdisk/bin
sudo cp /bin/bash ./lofsdisk/bin
sudo cp /bin/ls ./lofsdisk/bin
sudo cp /bin/echo ./lofsdisk/bin
sudo cp /bin/cat ./lofsdisk/bin
mkdir lofsdisk/lib
mkdir lofsdisk/lib64
mkdir lofsdisk/lib/x86_64-linux-gnu

list="$(ldd /bin/bash | egrep -o '/lib.*\.[0-9]')"
for i in $list; do cp  -v "$i" "./lofsdisk/${i}"; done
list="$(ldd /bin/bash | egrep -o '/lib64.*\.[0-9]')"
for i in $list; do cp  -v "$i" "./lofsdisk/${i}"; done
list="$(ldd /bin/cat | egrep -o '/lib.*\.[0-9]')"
for i in $list; do cp  -v "$i" "./lofsdisk/${i}"; done
list="$(ldd /bin/cat | egrep -o '/lib64.*\.[0-9]')"
for i in $list; do cp  -v "$i" "./lofsdisk/${i}"; done
list="$(ldd /bin/echo | egrep -o '/lib.*\.[0-9]')"
for i in $list; do cp  -v "$i" "./lofsdisk/${i}"; done
list="$(ldd /bin/echo | egrep -o '/lib64.*\.[0-9]')"
for i in $list; do cp  -v "$i" "./lofsdisk/${i}"; done
list="$(ldd /bin/ls | egrep -o '/lib.*\.[0-9]')"
for i in $list; do cp  -v "$i" "./lofsdisk/${i}"; done
list="$(ldd /bin/ls | egrep -o '/lib64.*\.[0-9]')"
for i in $list; do cp  -v "$i" "./lofsdisk/${i}"; done

cd lofsdisk
gcc ../ex2.c -o ex2.out
sudo chroot . ./ex2.out > ../ex2.txt
cd ..
gcc ex2.c -o ex2.out
./ex2.out >> ex2.txt
