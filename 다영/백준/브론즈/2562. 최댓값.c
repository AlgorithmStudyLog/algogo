#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int arr[9] = { 0 };
	int max = 0, index = 0;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
	}

	max = arr[0];

	for (int i = 1; i < 9; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			index = i;
		}
	}

	printf("%d %d", max, index+1);

	return 0;
}