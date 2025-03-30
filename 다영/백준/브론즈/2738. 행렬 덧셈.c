#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int x = 0, y = 0, sum = 0;
	int arr1[100][100] = {0};
	int arr2[100][100] = {0};

	scanf("%d %d", &x, &y);

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			scanf("%d", &arr1[i][j]);
		}
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			scanf("%d", &arr2[i][j]);
		}
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			sum = arr1[i][j] + arr2[i][j];
			printf("%d ", sum);
		}
		printf("\n");
	}

	return 0;
}