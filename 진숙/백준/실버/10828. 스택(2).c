#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 10000

typedef int element;
typedef struct{
    element *data;  //data는 포인터로
    int size;       //현재 크기
    int top;
}StackType;

// 스택 초기화 함수(top은 -1, size = 0, data는 동적 할당)
void init_stack(StackType *st);

// 공백 상태 검출
int is_empty(StackType *st);

// 포화 상태 검출
int is_full(StackType *st);

// 삽입 함수
void push(StackType *st, int num);

// 삭제 함수
int pop(StackType *st);

// 최상단 값 반환
int top(StackType *st);

// 크기 반환
int stackSize(StackType *st);

int main(){
    int cnt = 0;
    StackType st;
    init_stack(&st);

    scanf("%d", &cnt);

    for(int i = 0; i < cnt; i ++){
        char cmd[10];
        scanf("%s", cmd);

        if(strcmp(cmd, "push") == 0){
            int num = 0;
            scanf("%d", &num);
            push(&st, num);
        }
        else if(strcmp(cmd, "pop") == 0) printf("%d\n", pop(&st));
        else if(strcmp(cmd, "top") == 0) printf("%d\n", top(&st));
        else if(strcmp(cmd, "size") == 0) printf("%d\n", stackSize(&st));
        else if(strcmp(cmd, "empty") == 0) printf("%d\n", is_empty(&st));
    }

    free(st.data);  // 동적할당 해제
    return 0;
}


// 스택 초기화 함수(top은 -1, size = 0, data는 동적 할당)
void init_stack(StackType *st){
    (*st).top = -1;
    (*st).size = 0;
    (*st).data = (element *)malloc(MAX_STACK_SIZE * sizeof(element));
    
}

// 공백 상태 검출
int is_empty(StackType *st){
    if((*st).top == -1) return 1;
    return 0;
}

// 포화 상태 검출
int is_full(StackType *st){
    if((*st).top == MAX_STACK_SIZE-1) return 1;
    return 0;
}

// 삽입 함수
void push(StackType *st, int num){
    if(is_full(st)) exit(1);
    (*st).size++;
    (*st).top++;
    (*st).data[(*st).top] = num;
}

// 삭제 함수
int pop(StackType *st){
    if(is_empty(st)) return -1;
    (*st).size--;
    return (*st).data[(*st).top--]; 
}

// 최상단 값 반환
int top(StackType *st){
    if(is_empty(st)) return -1;
    return (*st).data[(*st).top];
}

// 크기 반환
int stackSize(StackType *st){
    return (*st).size;
}