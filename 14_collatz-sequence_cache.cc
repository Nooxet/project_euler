/*
*	Problem 14 - Find the longest Collatz sequence
*	for n < 1'000'000
*
*	Nox
*/

#include <stdio.h>
#include <iostream>
#include <unordered_map>

using namespace std;

long long collatz_length(long long);
void cacheit(long long, long long);

unordered_map<long long, long long> cache;

int main()
{
	long long biggest = 0;
	long long start_num = 0;


	for (long long i = 50000000; i > 0; i--) {
	//	cout << "i: " << i << " - ";
		long long len = collatz_length(i);
		//cout << "i: " << i << ", len: " << len << " seq: ";
		cacheit(i, len);
		if (len > biggest) {
			biggest = len;
			start_num = i;
		}
	}
	printf("The number %d gives the biggest chain of %d\n", start_num, biggest);
}

long long collatz_length(long long n)
{
	long long count = 1;
	while (n != 1) {
		auto it = cache.find(n);
		if (it != cache.end()) {
			//cout << "cached: " << it->first << endl;
			return count + it->second - 1;
		}
		//cout << " " << n;
		n = n % 2 == 0 ? n / 2 : 3 * n + 1;
		count++;
	}
	//cout << endl;
	return count;
}

void cacheit(long long n, long long len)
{
	while (n != 1) {
		if (cache.count(n) == 1) return;
		cache.insert(pair<long long, long long> (n, len--));
		n = n % 2 == 0 ? n / 2 : 3 * n + 1;
	}
}
