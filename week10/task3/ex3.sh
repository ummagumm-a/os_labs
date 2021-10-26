touch _ex3.txt
echo "blabla" >> _ex3.txt
chmod -x _ex3.txt
ls -la _ex3.txt >> ex3.txt
chmod 707 _ex3.txt
ls -la _ex3.txt >> ex3.txt
chmod uo+rw _ex3.txt
ls -la _ex3.txt >> ex3.txt
chmod g=u _ex3.txt
ls -la _ex3.txt >> ex3.txt