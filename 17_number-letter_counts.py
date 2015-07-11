#!/usr/bin/python

ones = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
		"ten", "eleven", "twelwe", "thirteen", "fourteen", "fifteen", "sixteen",
		"seventeen", "eighteen", "nineteen"]

tens = ["twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]

c_ones = [len(i) for i in ones]
c_tens = [len(i) for i in tens]
c_hund = [len(i) + len("hundred") for i in ones[0:9]]

cost = [c_ones, c_tens, c_hund]

sums = 0#len("onethousand")
idx = 0
for i in range(302, 303):
	j = i
	# do not add "and" in the word, i.e. four hundred comp. to. four hundred AND one
	if j % 100 == 0:
		sums -= len("and")
	if j % 100 < 20:
		sums += c_ones[(j % 100) - 1]
		j /= 100
		idx += 2
	else:
		sums += c_ones[(j % 10) - 1]
		j /= 10
		idx += 1
	
	if j % 10 != 0:
		if idx == 1:
			sums += cost[idx][(j % 10) - 2]
		if idx == 2:
			sums += cost[idx][(j % 10) - 1] + len("and")

	j /= 10

	idx += 1

	if j % 10 != 0:
		sums += cost[idx][(j % 10) - 1] + len("and")
	
	idx = 0

print sums
