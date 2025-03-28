// 미완성

#include <stdio.h>

int main(void) {

	int a[9] = { 0 };
	int A, B, C, sum = 0, cnt = 0;

	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);

	sum = A * B * C;

	while (1) {
		
		if (sum % 10 == 0) {
			a[0]++;
			sum = sum / 10;
		}
		else if (sum % 10 == 1) {
			a[1]++;
			sum  = sum / 10;
		}
		else if (sum % 10 == 2) {
			a[2]++;
			sum = sum / 10;
		}
		else if (sum % 10 == 3) {
			a[3]++;
			sum = sum / 10;
		}
		else if (sum % 10 == 4) {
			a[4]++;
			sum = sum / 10;
		}
		else if (sum % 10 == 5) {
			a[5]++;
			sum = sum / 10;
		}
		else if (sum % 10 == 6) {
			a[6]++;
			sum = sum / 10;
		}
		else if (sum % 10 == 7) {
			a[7]++;
			sum = sum / 10;
		}
		else if (sum % 10 == 8) {
			a[8]++;
			sum = sum / 10;
		}

	}

	printf("%d", sum);
	return 0;
}
