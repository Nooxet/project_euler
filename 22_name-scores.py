#!/usr/bin/python

#lines = [i.strip() for i in open('22.txt', 'r')]
lines = sorted(open('22.txt', 'r').read().split(','))
sums = 0
for line in range(len(lines)):
	interm = 0
	for ch in lines[line]:
		if ch != '"':
			interm += (ord(ch) - ord('A') + 1)

	sums += interm * (line + 1)

print sums
