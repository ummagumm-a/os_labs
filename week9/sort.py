#! /usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2021 ummagumma <ummagumma@ummagumma>
#
# Distributed under terms of the MIT license.

"""

"""


f = open("dataset.txt", "r")
n, m = map(int, f.readline().split())
times = [0] * m
numbers = [0] * m

for i in range(m):
    times[i], numbers[i] = map(int, f.readline().split())

f.close()

numbers = sorted(numbers)

f = open("sorted_dataset.txt", "w")
f.write(str(n) + " " + str(m) + "\n")
for i in range(m):
    f.write(str(times[i]) + " " + str(numbers[i]) + "\n")
f.close()
