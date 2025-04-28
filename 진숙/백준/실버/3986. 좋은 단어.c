#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100010

// 구조체 정의
typedef char element;
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

    int n = 0;   // 입력받을 단어 개수
    int cnt = 0; // 좋은 단어 개수 
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        char str[MAX_STACK_SIZE];
        scanf("%s", str);
        int len = strlen(str);
        
        push(&st, str[0]);
        for(int j = 1; j < len; j++){
            if(peek(&st) == str[j]) pop(&st);
            else push(&st, str[j]);
        }
        if(is_empty(&st)) cnt++;
        init_stack(&st);
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