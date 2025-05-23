#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

typedef int element;
typedef struct{
    int front;
    int rear;
    element data[MAX_SIZE];
} DQue;

void init_que(DQue *q);
void push_front(DQue *q, element item); 
void push_rear(DQue *q, element item); 
int pop_front(DQue *q);                
int pop_rear(DQue *q);       
int is_empty(DQue *q);             
int is_full(DQue *q);
int dq_size(DQue *q);           
void shift_right(DQue *q);
void print_dque(DQue *q);

int main() {
    int n = 0;
    scanf("%d", &n);

    DQue q;
    init_que(&q);
    // Que에 값을 넣으면서 역추적
    for(int i = n; i > 0; i--){
        push_front(&q, i);
        if(i == n){
            continue;
        }
        for(int j = 0; j < i; j++){
            int ele = pop_rear(&q);
            push_front(&q, ele);
        }
    }
    print_dque(&q);
    return 0;
}

void init_que(DQue *q){
    q->front = -1;
    q->rear = -1;
}

int is_empty(DQue *q){
    return q->front == q->rear;
}

int is_full(DQue *q){
    return q->rear == MAX_SIZE - 1;
}

void push_front(DQue *q, element item){
    if(is_full(q)) return;

    // 앞 공간에 여유가 없으면 하나씩 밀어주기
    if(q->front == -1){
        shift_right(q);
    }
    q->data[q->front--] = item;
}

void push_rear(DQue *q, element item){
    if(is_full(q)) return;
    q->rear++;
    q->data[q->rear] = item;
}

int pop_front(DQue *q){
    if(is_empty(q)) return -1;
    q->front++;
    return q->data[q->front];
}

int pop_rear(DQue *q){
    if(is_empty(q)) return -1;
    return q->data[q->rear--];
}

int dq_size(DQue *q){
    return q->rear - q->front;
}
           
void shift_right(DQue *q){
    for(int i = q->rear; i > q->front; i--){
        q->data[i+1] = q->data[i]; 
    }
    q->rear++;
    q->front++;
}


void print_dque(DQue *q){
    for(int i = q->front+1; i <= q->rear; i++){
        printf("%d ", q->data[i]);
    }
}

