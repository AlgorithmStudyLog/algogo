#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100010

typedef char element;
typedef struct{
    element data[MAX_STACK_SIZE];
    int top;
}STACK_TYPE;

void initStruct(STACK_TYPE *stack);
void push(STACK_TYPE *stack, element input);
void pop(STACK_TYPE *stack);
int is_empty(STACK_TYPE *stack);
int is_full(STACK_TYPE *stack);

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) {
    bool answer = true;
    STACK_TYPE stack;
    initStruct(&stack);
    
    int len = strlen(s);

    if(s[0] == ')') return false;
    for(int i = 0; i < len; i++){
        if(s[i] == '(') push(&stack, s[i]);
        if(s[i] == ')') pop(&stack);
    }

    if(stack.top != -1) answer = false;
    return answer;
}


void initStruct(STACK_TYPE *stack){
    // stack.top	    구조체 변수 stack의 멤버 접근
    // (*stack).top	    구조체 포인터 stack이 가리키는 구조체의 멤버 접근
    // stack->top	    위 방법을 단순화
    stack->top = -1;
}
int is_empty(STACK_TYPE *stack){
    if(stack->top == -1) return 1;
    return 0;
}
int is_full(STACK_TYPE *stack){
    if(stack->top == MAX_STACK_SIZE -1) return 1;
    return 0;
}

void push(STACK_TYPE *stack, element input){
    if(is_full(stack)) return;
    stack->top++;
    stack->data[stack->top] = input;
}
void pop(STACK_TYPE *stack){
    if(is_empty(stack)) return;
    stack->top--;
}