#!/usr/bin/python

import sys
from math import *

lines = [i.strip() for i in open('99.txt', 'r')]

biggest = -1
big_linenbr = -1

linenbr = 1
for i in lines:
	(base, exp) = i.split(',')
	(base, exp) = (float(base), float(exp))
	curr = exp * log(base)
	if curr > biggest:
		biggest = curr
		big_linenbr = linenbr

	linenbr += 1
print big_linenbr
