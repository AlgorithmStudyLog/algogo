#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    int cnt[26] = {0};      // 알파벳 개수 담을 배열
    char c = ' ';           // 가장 많이 사용된 알파벳 담을 변수
    int max = -1;           // 사용된 알파벳 개수의 최대값 구하기 위한 변수
    int len = 0;            // 문자열 길이 담을 변수 
    char str[1000000];      // 입력받은 문자열

    scanf("%s", str);
    len = strlen(str);

    // 사용된 알파벳 개수 세기
    for(int i = 0; i < len; i++){
        if(islower(str[i])) str[i] = toupper(str[i]);   // 소문자를 대문자로 바꾸기
        cnt[str[i]-'A']++;                              // 사용된 알파벳 개수 세기
    }

    // 가장 많이 사용된 알파벳 확인하기
    for(int i = 0; i < 26; i++){
        if(max <= cnt[i]){
            max = cnt[i];
            c = i + 'A';
        }
    }

    // max와 같은 개수인 알파벳 발견하면 c 에 '?' 저장하고 반복 종료
    for(int i = 0; i < 26; i++){
        if(max == cnt[i] && c != i + 'A'){
            printf("temp");
            c = '?';
            break;
        }
    }

    // 출력
    printf("%c", c);
    return 0;
}