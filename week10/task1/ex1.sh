#! /bin/sh
#
# ex1.sh
# Copyright (C) 2021 ummagumma <ummagumma@ummagumma>
#
# Distributed under terms of the MIT license.
#


touch _ex1.txt
echo "blabla" > _ex1.txt

ln _ex1.txt _ex1_1.txt
ln _ex1.txt _ex1_2.txt

touch ex1.txt
ls -i _ex1.txt >> ex1.txt
ls -i _ex1_1.txt >> ex1.txt
ls -i _ex1_2.txt >> ex1.txt
