#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 10000

int stack[MAX_STACK_SIZE];
int top_idx = -1;

void push(int x);
void pop();
void size();
void top();
void empty(); // 출력용
int isempty(); // 반환용

int main(){
    int n = 0;
    scanf("%d", &n);
    for(int i = 0 ; i < n; i++){
        char cmd[10];
        int x;
        scanf("%s", cmd);
        if(!strcmp(cmd, "push")){
            scanf("%d", &x);
            push(x);
        }
        if(!strcmp(cmd, "pop")) pop();
        if(!strcmp(cmd, "size")) size();
        if(!strcmp(cmd, "top")) top();
        if(!strcmp(cmd, "empty")) empty();
    }
    return 0;
}

// push X: 정수 X를 스택에 넣는 연산이다.
void push(int x){
    top_idx++;
    if(top_idx < MAX_STACK_SIZE){
        stack[top_idx] = x;
    }
}
// empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
void empty(){
    if(isempty()){
        printf("1\n");
    }else {
        printf("0\n");
    }
}
int isempty(){
    if(top_idx == -1){
        return 1;
    }else {
        return 0;
    }
}
// pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
void pop(){
    if(isempty()){
        printf("-1\n");
    }else{
        printf("%d\n", stack[top_idx--]);
    }
}
// size: 스택에 들어있는 정수의 개수를 출력한다.
void size(){
    if(isempty()){
        printf("0\n");
    }else{
        printf("%d\n", top_idx+1);
    }    
}
// top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
void top(){
    if(isempty()){
        printf("-1\n");
    }else{
        printf("%d\n", stack[top_idx]);
    }
}