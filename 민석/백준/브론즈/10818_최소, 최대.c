#include <stdio.h>

int main(void) {

	int a[100000] = { 0 }; // 문제 정수 갯수
	int i, N; 
	int max = 100000, min = -100000;

	scanf("%d", &N); // 5를 입력 받기 위함

	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}

	for (i = 0; i < N; i++) {
			if (max > a[i]) { // N의 수 중 최대 값 대조
					max = a[i];
			}
		
			if (min < a[i]) { // N의 수 중 최소 값 대조
					min = a[i];
			}
	}
	printf("%d ", max);
	printf("%d ", min);

	return 0;
}
