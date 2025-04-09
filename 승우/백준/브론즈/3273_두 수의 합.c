#include <stdio.h>
int main()
{
	int n, x;
	int i, j;
	int a[1000001];
	int cnt = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &x);

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] + a[j] == x)
			{
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}