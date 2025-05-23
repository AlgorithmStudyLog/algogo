// 요시푸스 문제.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNGINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

typedef struct
{
	int data[SIZE];
	int front;
	int rear;
}QueueType;

QueueType Q;

//원형 큐는 초기 값이 0
void init(QueueType* Q)
{
	Q->front = Q->rear = 0;
}

int empty(QueueType* Q)
{
	return Q->front == Q->rear;
}

int full(QueueType* Q, int k)
{
	return Q->front == (Q->rear + 1) % k;
}

void push(QueueType* Q, int n, int k)
{
	if (full(Q, k))
	{
		return;
	}
	else
	{
		Q->rear = (Q->rear + 1) % k;
		Q->data[Q->rear] = n;
	}
}

int pop(QueueType* Q, int k)
{
	if (empty(Q))
	{
		return;
	}
	Q->front = (Q->front + 1) % k;
	return Q->data[Q->front];
}

int back(QueueType* Q)
{
	if (!empty(Q))
	{
		return (Q->data[Q->rear]);
	}
}


int main(void)
{
	int N, K;
	int i, j;
	int num[1000] = { 0 };

	scanf("%d %d", &N, &K);

	init(&Q);

	for (i = 0;i < N;i++) {
		for (j = 0;j < K;j++)
		{
			push(&Q, j, K);
		}
		num[i] = back(&Q);
	}

}

/*
1~N번 원탁

K번째 사람 제거

ex) 7,3
3n >> 7->1 처리

3, 6, 9, 12 ,15 >> 3, 6, 9-7, 12-7, 15-14 >> 3, 6, 2, 5, 1 >> 미리 제거된 번호만큼 이동
>> 3, 6, 2, 5+2, 1+4...

queue

원형 큐?

1 2 3

4 5 6

7 1 2

4 5 7

1 4 5

1 4 1

4 4 4
*/