#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <stdio.h>

/*1. 자연수를 입력 받는다. (반복)
	1-1. 입력 받는 수는 1~100까지의 10의 배수이다. (조건)
  2. 평균을 구한다.
	2-2. 총합을 구한다. (반복)
	2-3. 총합을 5로 나눈다.
  3. 오름차순으로 정렬한다. (반복)
	3-1. 외부 루프(i)는 더 작다고 가정하는 숫자이다.
	3-2. 내부 루프(j)는 비교 할 숫자이다.
	3-3. i보다 j가 더 작으면 두 값을 바꾼다. (조건)
  4. 평균과 중앙값을 출력한다.*/

int main(void) {

	int arr[5] = { 0 };
	int sum = 0, avg = 0;

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
		assert((arr[i] % 10 == 0) && (arr[i] > 0 && arr[i] < 100));
		sum += arr[i];
	}

	avg = sum / 5;

	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	printf("%d\n", avg);
	printf("%d\n", arr[2]);

	return 0;
}