// 코딩테스트_올바른괄호찾기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.void push ();
char stack[100000] = { 0 };
void push(int x);
char pop();
int empty();
int top = -1;

bool solution(const char* s)
{
    bool answer = true;
    int len = strlen(s);

    if (s[0] == ")")
    {
        return false;
    }

    push(s[0]);

    for (int i = 1; i < len; i++)
    {
        if (s[i] == ")") {
            if (s[i - 1] == "(")
                pop();
            else push(s[i]);
        }
        else
            push(s[i]);
    }

    if (empty() == 1) return true;
    else return false;

    return answer;
}
void push(int x)
{
    stack[++top] = x;
}
char pop()
{
    return stack[top--];
}
int empty()
{
    if (top < 0) return 1;
    else return 0;
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
