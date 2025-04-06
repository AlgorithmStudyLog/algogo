#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, const char* overwrite_string, int s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(my_string) + 1;
    char* answer = (char*)malloc(len * sizeof(char));
    strcpy(answer, my_string);
    
    for(int i = s; i < strlen(overwrite_string) + s; i++){
        printf("%c", answer[i]);
        answer[i] = overwrite_string[i-s];
    }    
    return answer;
}

int main(){
    return 0;
}