#include <stdio.h>
#include <string.h>
#define MAX 30

char stack[MAX][MAX];
char popElement[MAX];
int top = -1;

int is_full();
int is_empty();
void push(char* item);
char* pop();

int main(){
    int n = 0;
    scanf("%d", &n);
    getchar();

    // 입력받기
    for(int i = 0; i < n ; i++){
        char temp[MAX];
        fgets(temp, MAX, stdin);
        temp[strcspn(temp, "\n")] = '\0';  // 줄바꿈 제거
        push(temp);
    }   

    // 역순으로 출력하기
    for(int i = 0; i < n; i++){
        printf("%s", pop());
    }
    return 0;
}
int is_full(){
    return top == (MAX - 1);
}
int is_empty(){
    return top == -1;
}
void push(char* item){
    if(is_full()){
        return;
    }
    // 단어 단위로 분리하여 스택에 저장
    char* word = strtok(item, " ");  // 공백을 기준으로 첫 단어를 분리
    while(word != NULL){
        strcpy(stack[top], word);  // 단어를 스택에 저장
        word = strtok(NULL, " ");  // 다음 단어로 이동
    }
}
char* pop(){
    if(is_empty()){
        return NULL;
    }
    strcpy(popElement, stack[top--]);  // top에 있는 문자열을 temp에 복사하고, top을 감소시킴
    return popElement;  // 복사한 문자열을 반환
}