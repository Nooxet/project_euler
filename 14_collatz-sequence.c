
#include <stdio.h>

int collatz(unsigned long j)
{
	int count = 1;
	while (j != 1) {
		count ++;
		j = j % 2 == 0 ? j / 2 : 3 * j + 1;
	}
	return count;
}

int main()
{
	int biggest = 0;
	int len = 0;
	int longest = 0;
	
	for (int i = 2; i < 1000000; i++) {
		len = collatz(i);
		if (len > biggest) {
			biggest = len;
			longest = i;
		}
	}

	printf("longest: %d (%d)\n", longest, biggest);
}
