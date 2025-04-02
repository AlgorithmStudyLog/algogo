#include <stdio.h>
int main()
{
	int num, i;
	int cnt[11] = { 0 };

	while (1)
	{
		scanf("%d", &num);
		if (num < 1 || num > 10)
			break;
		cnt[num]++;
	}

	return 0;
}

