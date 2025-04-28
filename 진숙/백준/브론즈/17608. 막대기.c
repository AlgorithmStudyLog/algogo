#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100000

// 구조체 정의
typedef int element;
typedef struct{
    element data[MAX_STACK_SIZE];
    int top;
} Stack;

// 함수 선언
void init_stack(Stack *st);
int is_empty(Stack *st);
int is_full(Stack *st);
void push(Stack *st, element e);
element pop(Stack *st);
element peek(Stack *st);

int main(){
    Stack st;
    init_stack(&st);
    
    // 입력 + push
    int n = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int temp = 0;
        scanf("%d", &temp);
        push(&st, temp);
    }

    // pop하면서 확인하기
    int pivot = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int popElement = pop(&st);
        if(pivot < popElement){
            pivot = popElement;
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}

// 함수 정의
void init_stack(Stack *st){
    st -> top = -1;
}
int is_empty(Stack *st){
    if(st -> top == -1) return 1;
    return 0;
}
int is_full(Stack *st){
    if(st -> top == MAX_STACK_SIZE -1 ) return 1;
    return 0;
}
void push(Stack *st, element e){
    if(is_full(st)) return;
    st -> top++;
    (*st).data[(*st).top] = e;
}
element pop(Stack *st){
    if(is_empty(st)) return;
    return (*st).data[(*st).top--];
}
element peek(Stack *st){
    return (*st).data[(*st).top];
}