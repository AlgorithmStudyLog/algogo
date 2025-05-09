#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

typedef int element;
typedef struct{
    int front;
    int rear;
    element data[MAX_SIZE];
} DQue;

void init_que(DQue *q);
void push(DQue *q, element item); 
int pop_front(DQue *q);                
int is_empty(DQue *q);             
int is_full(DQue *q);
int dq_size(DQue *q);           
void print_dque(DQue *q);
void input_que(DQue *q, int n);

int main() {
    int n = 0;
    scanf("%d", &n);

    DQue q;
    init_que(&q);
    input_que(&q, n); //Que에 값을 한번에 넣기 (1~n)

    while(1){
        if(dq_size(&q) == 1) break;
        pop_front(&q);
        int item = pop_front(&q);
        push(&q, item);
    }
    print_dque(&q);

    return 0;
}

void input_que(DQue *q, int n){
    for(int i = 1; i <= n; i++){
        push(q, i);
    }
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

void push(DQue *q, element item){
    if(is_full(q)) return;
    q->rear++;
    q->data[q->rear] = item;
}

int pop_front(DQue *q){
    if(is_empty(q)) return -1;
    q->front++;
    return q->data[q->front];
}
int dq_size(DQue *q){
    return q->rear - q->front;
}
void print_dque(DQue *q){
    for(int i = q->front+1; i <= q->rear; i++){
        printf("%d ", q->data[i]);
    }
}
