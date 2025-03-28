#include <stdio.h>
int main()
{
	int a[9][9] = { {0,0} };
	int i, j;
	int q, w;
	int max = 0;

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (max < a[i][j])
			{
				max = a[i][j];
				q = i + 1;
				w = j + 1;
			}
		}
	}
	printf("%d\n", max);
	printf("%d %d", q, w);

	return 0;
}