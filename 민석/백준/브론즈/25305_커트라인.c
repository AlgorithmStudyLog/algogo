#include <stdio.h>

int main(void) {

	int i, j, max = 0;
	int n, k; // n = 학생 수, k, 가장 높은 수
	int arr[5];

	scanf("%d %d", &n, &k);

	for (i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
	}

	for (j = 0; j < 5; j++) {
		if (arr[j] < arr[0] && arr[j] > arr[3]) {
			printf("%d ", arr[j]);
		}
	}

	return 0;
}
