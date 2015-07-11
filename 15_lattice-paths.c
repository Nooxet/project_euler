#include <stdio.h>

static int count = 0;

void path(int mat[21][21], int N, int i, int j)
{
	if (i == N && j == N) {
		count++;
		return;
	}
	/*for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("[%d] ", mat[i][j]);
		}
		printf("\n");
	}*/
	
	if (i == N) {
		path(mat, N, i, j+1);
	} else if (j == N) {
		path(mat, N, i+1, j);
	} else {
		path(mat, N, i+1, j);
		path(mat, N, i, j+1);
	}
	

}

int main()
{
	int mat[21][21] = { 0 };

	path(mat, 20, 0, 0);

	printf("count: %d\n", count);

	return 0;
}
