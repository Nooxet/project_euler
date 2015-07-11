#include <stdio.h>

static int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
static int count = 0;
static int flag = 0;

void coin_sums(int rest, int latest)
{
	/* First recursive solution */
	if (rest < 0) return;

	if (rest == 0) {
		/* No change left, done */
		count++;
		return;
	}

	for (int i = 7; i >= 0; i--) {
		if (coins[i] <= latest) {
			coin_sums(rest - coins[i], coins[i]);
		}
	}
}

int coin_sums2(int coin, int rest)
{
	/* Second, cleaner recursion.
	 * Reminds of knapsack problem solution
	 */

	// now, we are only using 1-pence coins which will solve the problem
	if (!coin) return 1;

	if (rest < 0) return 0;

	return coin_sums2(coin, rest-coins[coin]) + coin_sums2(coin-1, rest);
}

int main()
{
	coin_sums(200, 200);
	printf("Number of ways to make £2: %d\n", count);

	int num = coin_sums2(7, 200);
	printf("Number of ways to make £2 (better alg.): %d\n", num);
	return 0;
}
