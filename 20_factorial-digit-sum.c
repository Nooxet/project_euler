/*
*	Problem 20 - Calculate digit sum of 100!
*	Use "-lm" flag
*	Nox
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorial_digit_sum(char *, int, int);
void multiplicate(char *, int, int);

int main(void)
{
	double tmp = 0;
	for (int i = 1; i <= 100; i++) {
		tmp += log10(i);
	}
	// digit size
	int size = floor(tmp) + 1;

	/* array to store the result, with 1 as init */
	char *res = malloc(size);
	res[0] = 1;

	printf("Digit sum of 100!: %d\n", factorial_digit_sum(res, 100, size));
}

int factorial_digit_sum(char *res, int n, int size)
{
	/* perform factorial form 1 to n */
	for (int i = 2; i <= n; i++) {
		multiplicate(res, i, size);
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
