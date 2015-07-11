#!/usr/bin/python

import sys

def main(filename):
	with open(filename, 'r') as f:
		lines = [line.strip() for line in f]

	matrix = [[0 for x in range(len(lines))] for x in range(len(lines))]
	for row in range(len(lines)):
		curr_row = lines[row].split(' ')
		for col in range(len(curr_row)):
			matrix[row][col] = int(curr_row[col])

	print "Maximum sum in triangle:", find_max(matrix, 0, 0)
	

mem = {}
def find_max(matrix, row, col):
	"""
	Recursive method to find the maximum sum in a path
	in the triangle, using dynamic programming
	"""
	if col >= len(matrix[0]) or row >= len(matrix[0]):
		return 0
	
	S = (row+1, col)	# going south in the matrix
	SE = (row+1, col+1)	# going south-east in the matrix
	if S in mem:
		a = mem[S]
	else:
		a = find_max(matrix, row+1, col)
		mem[S] = a # cache result
	
	if SE in mem:
		b = mem[SE]
	else:
		b = find_max(matrix, row+1, col+1)
		mem[SE] = b

	return matrix[row][col] + max(a, b)


if __name__ == '__main__':
	if len(sys.argv) != 2:
		print "Usage: %s <filename>" % sys.argv[0]
		sys.exit()

	main(sys.argv[1])
