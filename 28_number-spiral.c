#include <stdio.h>

int main()
{
	int sum = 0;
	int add = 2;
	int count = 1;
	int num = 1;
	while (num <= 1001*1001) {	
		sum += num;
		num += add;
		if (count % 4 == 0) {
			add += 2;
		}	
		count++;
	}
	printf("sum: %d\n", sum);
}
