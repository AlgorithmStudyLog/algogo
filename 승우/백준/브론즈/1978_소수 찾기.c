#include <stdio.h>

int main()
{
	int i, j, N, K;
	int arr[101];
	int cnt = 0;


	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < N; i++)
	{
		K = arr[i];
		if (K < 2)
			continue;

		for (j = 2; j < K; j++)
		{
			if ( K % j == 0)
				break;
		}

		if (j == K)
			cnt++;
	}

	printf("%d", cnt);
	
	return 0;
}