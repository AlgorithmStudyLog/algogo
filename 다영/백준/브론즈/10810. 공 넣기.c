#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int main(void) {

	int basket = 0;				//바구니 개수
	int cnt = 0;				//공 넣는 횟수(회전 수)
	int a = 0, b = 0, c = 0;	//첫 바구니, 끝 바구니, 공 번호
	int* arr = NULL;			//각 바구니를 나타내는 배열

	//1. basket과 cnt를 입력 받는다.
	scanf("%d %d", &basket, &cnt);

	//1-1. 크기가 basket인 배열 생성
	//1-2. 0으로 초기화하여 공이 없는 바구니는 0으로 출력 되게 한다.
	arr = (int*)calloc(sizeof(int) * basket, sizeof(int) * basket);

	//2. a, b, c를 입력 받는다.
	//3. a부터 b까지 c번호가 붙은 공을 넣는다.
	//3-1. 배열의 인덱스는 0부터 시작하니, 바구니 번호에 1씩 빼준다.
	for (int i = 0; i < cnt; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		for (int j = a - 1; j <= b - 1; j++)
		{
			arr[j] = c;
		}
		
	}

	//4. 1번부터 basket번까지 넣어진 공 번호를 출력한다.
	for (int i = 0; i < basket; i++)
	{
		printf("%d ", arr[i]);
	}

	free(arr);

	return 0;
}
