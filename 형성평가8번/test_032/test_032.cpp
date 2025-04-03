// test_032.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N[4][2] = { 0 };
	int sum_row[2] = { 0 };		//행
	int sum_colunm[4] = { 0 };	//열
	int sum_all = 0;			//전체
	int avg_row, avg_colunm, avg_all;
	int i, j;

	for (i = 0;i < 4;i++) {
		for (j = 0;j < 2;j++) {
			scanf("%d", &N[i][j]);
			
			sum_all += N[i][j];
		}
	}

	for (i = 0;i < 4;i++) {
		for (j = 0;j < 2;j++) {
			sum_row[j] += N[i][j];
		}
	}
	for (i = 0;i < 2;i++) {
		for (j = 0;j < 4;j++) {
			sum_colunm[j] += N[j][i];
		}
	}
	
	avg_all = sum_all / 8;

	for (i = 0;i < 4;i++) {
		avg_colunm = sum_colunm[i] / 2;
		printf("%d ", avg_colunm);
	}
	printf("\n");
	for (i = 0;i < 2;i++) {
		avg_row = sum_row[i] / 4;
		printf("%d ", avg_row);
	}
	printf("\n");
	printf("%d", avg_all);

	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
