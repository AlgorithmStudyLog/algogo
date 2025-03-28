#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ROW 9
#define COL 9

int main(void) {

	int arr[ROW][COL] = { 0 };
	int i, j;
	int max = 0;			//최댓값
	int row = 0, col = 0;	//최댓값 좌표

	//배열 입력
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (max < arr[i][j]) {
				max = arr[i][j];
				row = i;
				col = j;
				//조건 만족 시 최댓값과 좌표 저장
			}
		}
	}

	//좌표가 0이 아닌 1부터 시작하기 때문에 +1
	printf("%d\n", max);
	printf("%d %d\n", row + 1, col + 1);

	return 0;
}