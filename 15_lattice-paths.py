#!/usr/bin/python

count = 0
cache = {}

def path(i, j, N):
	global count
	global cache

	if (i == N and j == N):
		count += 1
		return
	
	if (i, j) in cache:
		print "in cache: ", (i, j)
		count += 1
		return
	else:
		cache[(i, j)] = 42
		print (i, j)
	
	if (i == N):
		path(i, j+1, N)
	elif (j == N):
		path(i+1, j, N)
	else:
		path(i+1, j, N)
		path(i, j+1, N)

N = int(raw_input("Enter size of grid: "))
path(0, 0, N)
print count
