#include <stdio.h>
#include <string.h>

int main(){
    char s[1000];
    int i = 0;

    scanf("%s", s);
    scanf("%d", &i);

    printf("%c", s[i-1]);

    return 0;
}



/*
1. 입력받은 단어를 저장할 문자열(s)을 만든다
    1-1. 단어의 길이는 최대 1000글자
    1-2. 문자 배열의 크기는 1000으로 지정
2. 입력받은 정수를 저장할 변수(i)를 만든다 
3. 문자열(s)을 입력받는다
4. 정수(i)를 입력받는다
5. 문자열의 정수(i)번째 문자를 출력한다 
*/