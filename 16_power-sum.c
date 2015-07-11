/*
*	Problem 16 - Calculate the sum of the digits of 2**1000
*	Use "-lm" flag
*	Nox
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int power_digit_sum(char *, int);
void multiplicate(char *, int, int);


int main(void)
{
	/* calculate the size of the number */
	int size = floor(1000*log10(2)) + 1;

	/* array to store the result, with 1 as init */
	char *res = malloc(size);
	res[0] = 1;
	
	/* do the magic */
	printf("Sum of digits in 2^1000: %d\n", power_digit_sum(res, size));
}

int power_digit_sum(char *res, int size)
{
	/* multiply 2 by itself 1000 times */
	for (int i = 1; i <= 1000; i++) {
		multiplicate(res, 2, size);
	}

	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += res[i];
	}
	return sum; 
}

void multiplicate(char *res, int num, int size)
{
	int rem = 0;
	int partial;
	for (int i = 0; i < size; i++) {
		// current partial result plus a previous remainder
		partial = res[i] * num + rem;
		// save the ones plus at the current position
		res[i] = (partial) % 10;
		// calculate the remainder for next step
		rem = partial / 10;
	}
}
