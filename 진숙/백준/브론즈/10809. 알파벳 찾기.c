#include <stdio.h>
#include <string.h>

int main(){
    char str[101];                              // 입력받은 문자열 저장할 변수
    int alpha[26] = {0};                        // 알파벳 위치 확인할 배열
    for(int i = 0; i < 26; i++) alpha[i] = -1;  // alpha 전체를 -1로 초기화

    scanf("%s", str);
    for(int i = 0; i < strlen(str); i++){
        // 처음 사용된 위치 저장
        if(alpha[str[i]-'a'] == -1) alpha[str[i]-'a'] = i;
    }
    
    // 출력
    for(int i = 0; i < 26; i++){
        printf("%d ", alpha[i]);
    }    
    return 0;
}