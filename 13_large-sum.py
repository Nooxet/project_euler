#!/usr/bin/python

f = open('13.txt', 'r')

lines = f.readlines()

f.close()

sums = 0
for line in lines:
	sums += long(line)

print str(sums)[0:10]
