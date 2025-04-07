#include <stdio.h>

int main(void) {

	int arr[9][9] = {{ 0 }};
	int i, j, max = 0;

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			scanf("%d", &arr[i][j]);
		}

		for (i = 0; i < 9; i++) 
		{
			for (j = 0; j < 9; j++) 
			{
				if (max < arr[i][j])
				{
					max = arr[i][j];
					i += 1;
					j += 1;
				}
			}
		}
		printf("\n");
	}

	printf("%d", max);
	printf("%d", j);

	return 0;
}