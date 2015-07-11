#!/usr/bin/python

def has_eight(n):
	divisors = 0
	for i in range(2, n/2 + 2):
		if n % i == 0:
			divisors += 1

	divisors += 2 # 1 and n
	if divisors == 8:
		return True
	return False

def divisor_count(x):
	dc = 0
	for i in range(1, x+1):
		if has_eight(i):
			dc += 1

	return dc

x = long(raw_input("Enter x: "))
print divisor_count(x)
