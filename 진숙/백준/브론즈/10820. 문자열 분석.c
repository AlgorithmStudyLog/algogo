#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_STRING_SIZE 110

void output(char str[]);

int main(){
    char str[MAX_STRING_SIZE] = {};
    // 입력 종료 조건은 EOF(End of File). 더 이상 입력이 없을 때 자동으로 종료
    while(fgets(str, MAX_STRING_SIZE, stdin)!= NULL){
        // gets(): 개행문자를 \n로 대치, 오버플로우 위험 권장X
        // fgets(): 개행문자까지 저장 (마지막 개행문자를 space++ 안하도록 주의)
        output(str);
    }
    return 0;
}

void output(char str[]){
    int lower = 0, upper = 0, number = 0, space = 0;
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if(islower(str[i])) lower++;
        else if(isupper(str[i])) upper++;
        else if(isdigit(str[i])) number++;
        // fgets(): 개행문자까지 저장 (마지막 개행문자를 space++ 안하도록 주의)
        else if(isspace(str[i]) && str[i] != '\n') space++;
    }
    printf("%d %d %d %d\n", lower, upper, number, space);
}