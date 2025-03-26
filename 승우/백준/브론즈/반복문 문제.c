#include <stdio.h>

int main()

{
	int i, j, n;
	scanf("%d", &n);
	int num;


	for (i = 1; i <= 3; i++)
	{
		num = 2 * i + (i - 1) * 4 - 1;
		for (j = 1; j <= n; j++)
		{
			printf("%d ", num);
			num += 2;
			if (num > 9)
				num = 1;
		}
		printf("\n");
	}


	return 0;
}