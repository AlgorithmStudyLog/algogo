#include <stdio.h>
int main()
{
	int i, j;
	int N, M;
	int a[100][100] = { 0 }, b[100][100] = { 0 };


	scanf("%d %d", &N, &M);



	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}


	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%d ", a[i][j] + b[i][j]);
		}
		printf("\n");
	}


	return 0;
}