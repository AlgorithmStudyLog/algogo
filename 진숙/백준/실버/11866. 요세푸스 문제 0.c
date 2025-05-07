#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

typedef int element;
typedef struct{
    int front;
    int rear;
    element data[MAX_SIZE];
} Que;

void init_que(Que *q);
void enque(Que *q, element item); 
int deque(Que *q);                
int is_empty(Que *q);             
int is_full(Que *q);                

int main() {
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);

    // Que에 값을 넣기
    Que q;
    init_que(&q);
    for(int i = 1; i < n+1; i++){
        enque(&q, i);
    }
    
    // 앞에서부터 빼면서 확인하기
    int idx = 0;
    int* arr = (int*)malloc(sizeof(int) * n);
    while(1){
        for(int i = 0; i < k; i++){
            if(i == k-1){
                arr[idx] = deque(&q);
                idx++;
                break;
            }
            enque(&q, deque(&q));
        }
        if(idx == n) break;
    }


    printf("<");
    for(int i = 0; i < n; i++){
        if(i == n-1) printf("%d", arr[i]);
        else printf("%d, ", arr[i]);
    }
    printf(">");

    free(arr);
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
void enque(Que *q, element item){
    if(is_full(q)) return;
    q->rear++;
    q->data[q->rear] = item;
}
int deque(Que *q){
    if(is_empty(q)) return -1;
    q->front++;
    return q->data[q->front];
}