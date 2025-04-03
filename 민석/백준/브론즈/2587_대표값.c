#include <stdio.h>

int main(void) {
	
	int i, j, ij, sum = 0;
	int arr[5] = { 0 };

	for (i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	int avg = sum / 5;
	for (i = 0; i < 4; i++) {
		for (j = i + 1; j < 5; j++) {
			if (arr[i] > arr[j]) { // 오름차순 정렬
				ij = arr[i];
				arr[i] = arr[j];
				arr[j] = ij;
			}
		}
	}
		printf("%d\n", avg); // 평균
		printf("%d", arr[2]); // 중앙 값 0 1 2

}

// 평균 문제
// 주어진 모든 합을 수의 개수로 나눔 10 + 20 + 30 = 60 / 3; 같은 개념
// 출력 1. 평균 / 2. 중앙 값
