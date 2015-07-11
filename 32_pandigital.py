#!/usr/bin/python

import sys
from math import *

def is_unique(num):
	l = []
	for i in range(0, len(num)):
		if (num[i] not in l) and (num[i] != '0'):
			l.append(num[i])
		else:
			return False
	return True
		
def is_pandigital(num):
	for i in range(1, int(ceil(sqrt(num)))):
		if num % i == 0:
			tmp = num / i
			str_num = str(num).join(str(i)).join(str(tmp))
			#print "a: %d\nb: %d\nc: %d" % (num, i, tmp)
			if contains_all(str_num):
				return True
	return False

def contains_all(num):
	for i in range(1, 10):
		if str(i) not in num:
			return False
	return True

sum_pandigital = 0

for i in range(1000, 1000000):
	#if is_unique(str(i)) == True:
	if is_pandigital(i) == True:
#		print i
		sum_pandigital += i

print sum_pandigital
