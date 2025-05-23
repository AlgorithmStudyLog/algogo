#include <stdio.h>

int main() 
{
	int r[42] = { 0 };
	int x, i, c = 0;

	for (i = 0; i < 10; i++) 
	{
		scanf("%d", &x);
		r[x % 42] = 1; // 마지막 1로 표시 된 입력 값 나머지 구하기
	}
	for (i = 0; i < 42; i++) // 42까지 반복
	{
		c += r[i]; // 42까지 반복 된 값을 c에 누적
	}

	printf("\n");
	printf("%d\n", c); // c 출력
	return 0;
}
