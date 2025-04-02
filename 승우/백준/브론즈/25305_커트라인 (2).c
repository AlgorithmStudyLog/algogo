#include <stdio.h>
int main()
{
	int N, K;
	int i, j, l;
	scanf("%d %d", &N, &K);
	int S[1000];

	for (i = 0; i < N; i++)
	{
		scanf("%d", &S[i]);
	}

	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < N - 1 - i; j++)
		{
			if (S[j] < S[j + 1])
			{
				l = S[j];
				S[j] = S[j + 1];
				S[j + 1] = l;
			}
		}
	}
	printf("%d\n", S[K - 1]);


	return 0;
}