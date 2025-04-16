#include <stdio.h>

int main() {
    char c; // 문자
    int cnt = 0; // 단어의 갯수
    int is_word = 0; // 내가 지금 단어 안에 있는지 아닌지 표시하는 깃발같은 변수

    while (scanf("%c", &c) == 1) // 문자를 하나씩 입력받다가 들어오면 계속 반복
    {
        if (c == ' ' || c == '\n') 
        {
            is_word = 0;  // 입력이 공백이면 0으로 변형
        }
        else if (!is_word) // 새로운 단어
        {
            is_word = 1; 
            cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}