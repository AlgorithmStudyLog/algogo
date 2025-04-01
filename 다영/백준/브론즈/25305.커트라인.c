#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int main(void) {

	int n = 0;			//응시자 수
	int k = 0;			//상 받는 수
	int* x = NULL;		//점수 배열

	scanf("%d %d", &n, &k);
	x = (int*)malloc(sizeof(int) * n);

	//점수 입력
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}

	//내림차순 정렬
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (x[i] < x[j])
			{
				int temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	}

	//배열은 0부터 시작
	printf("%d", x[k-1]);

	free(x);

	return 0;
}