
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10000

typedef int element;
typedef struct{
    int front;
    int rear;
    element data[MAX_SIZE];
} Que;

void init_que(Que *q);
void enqueue(Que *q, element item); // push
int dequeue(Que *q);                // pop
int is_empty(Que *q);               // empty
int is_full(Que *q);                
void print_front(Que *q);           // front
void print_rear(Que *q);            // back
void print_size(Que *q);            // size

int main(){
    int n = 0;
    scanf("%d", &n);

    Que q;                 
    init_que(&q);          

    for(int i = 0; i < n; i++){
        char cmd[10];
        scanf("%s", cmd);

        if(strcmp(cmd, "push") == 0){ 
            int item = 0;
            scanf("%d", &item);
            enqueue(&q, item);
        } else if(strcmp(cmd, "pop") == 0){
            int res = dequeue(&q);
            printf("%d\n", res);
        } else if(strcmp(cmd, "size") == 0){
            print_size(&q);
        } else if(strcmp(cmd, "empty") == 0){
            printf("%d\n", is_empty(&q));
        } else if(strcmp(cmd, "front") == 0){
            print_front(&q);
        } else if(strcmp(cmd, "back") == 0){
            print_rear(&q);
        }
    }
    return 0;
}

void init_que(Que *q){
    q->front = -1;
    q->rear = -1;
}
int is_empty(Que *q){
    return q->front == q->rear;
}
int is_full(Que *q){
    return q->rear == MAX_SIZE - 1;
}
void enqueue(Que *q, element item){
    if(is_full(q)) return;
    q->rear++;
    q->data[q->rear] = item;
}
int dequeue(Que *q){
    if(is_empty(q)) return -1;
    q->front++;
    return q->data[q->front];
}

void print_front(Que *q){
    if(is_empty(q)) printf("%d\n", -1);
    else printf("%d\n", q->data[q->front + 1]); 
}
void print_rear(Que *q){
    if(is_empty(q)) printf("%d\n", -1);
    else printf("%d\n", q->data[q->rear]);
}
void print_size(Que *q){
    printf("%d\n", q->rear - q->front);
}
