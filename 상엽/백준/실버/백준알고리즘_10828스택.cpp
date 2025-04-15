// 백준알고리즘_10828스택.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int stack[10000];
int top = -1;			//초기 스택 비어있음을 의미
int output[10000];

int IsEmpty()			//스택 비어있는지 체크
{
	if (top < 0) return true;
	else return false;
}

int IsFull()				//해당 스택 공간이 가득 차있는지 체크, '-1'은 '\n' 저장 공간 한칸을 의미
{
	if (top >= 10000 - 1)
		return true;
	else return false;
}

void push(int x)			//사이즈를 체크하여 새로 값을 쌓음
{
	if (IsFull() == true)
		printf("full");
	else
		stack[++top] = x;

}
int pop()					//맨 위에 쌓은 값을 제거
{
	if (IsEmpty() == true)
		return -1;
	else
		return stack[top--];
}

int main(void)
{
	int N;								//명령 개수
	int a, i;
	char text[10] = { };				//명령
	int cnt = 0;

	scanf("%d", &N);

	for (i = 0;i < N;i++) {
		scanf("%s", &text);

		if (strcmp(text, "push") == 0) {		//strcmp : 문자열 비교 함수
			scanf("%d", &a);
			push(a);
		}
		else if (strcmp(text, "pop") == 0) {
			output[cnt] = pop();
			cnt++;
		}
		else if (strcmp(text, "size") == 0) {
			output[cnt] = top + 1;
			cnt++;
		}
		else if (strcmp(text, "top") == 0) {
			if (top != -1) {
				output[cnt] = stack[top];
			}
			else 
				output[cnt] = -1;
			cnt++;
		}
		else if(strcmp(text, "empty") == 0){
			output[cnt] = IsEmpty();
			cnt++;
		}
	}
	for (i = 0;i < cnt;i++) {
		printf("%d\n", output[i]);
	}

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
