// 백준 큐.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 10000

//큐 생성
typedef struct
{
	int data[SIZE];
	int front;
	int rear;
}QueueType;

QueueType Q;

void init(QueueType *Q)		//front, back 값 초기화
{
	Q->front = -1;
	Q->rear = -1;
}

bool empty(QueueType *Q);
bool full(QueueType *Q);

int size(QueueType* Q);

int front(QueueType* Q);
int back(QueueType* Q);

void push(QueueType* Q, int n);
int pop(QueueType* Q);

int main(void)
{

	int N;			//명령 개수
	int a, i;
	char text[10] = {};

	init(&Q);

	scanf("%d", &N);

	for (i = 0;i < N;i++)
	{
		scanf("%s", &text);

		if (strcmp(text, "push") == 0)
		{
			scanf("%d", &a);
			push(&Q, a);
		}
		else if (strcmp(text, "pop") == 0)
		{
			printf("%d", pop(&Q));
		}
		else if (strcmp(text, "size") == 0)
		{
			printf("%d", size(&Q));
		}
		else if (strcmp(text, "empty") == 0)
		{
			printf("%d", empty(&Q));
		}
		else if (strcmp(text, "front") == 0)
		{
			printf("%d", front(&Q));
		}
		else if (strcmp(text, "back") == 0)
		{
			printf("%d", back(&Q));
		}
		printf("\n");
	}

	return 0;
}

bool empty(QueueType *Q)
{
	if (Q->front == Q->rear)
	{
		return true;
	}
	else return false;
}
bool full(QueueType *Q)
{
	if (Q->rear == SIZE - 1)
	{
		return true;
	}
	else return false;
}

int size(QueueType *Q)
{
	if (!empty(Q)) {
		return (Q->rear + 1);
	}
	else return 0;
}

int front(QueueType* Q)
{
	if (!empty(Q))
	{
		return (Q->data[Q->front + 1]);
	}
	else return -1;
}
int back(QueueType* Q)
{
	if (!empty(Q))
	{
		return (Q->data[Q->rear]);
	}
	else return -1;
}

//값을 입력하면 rear값을 1올리고 push >>index번호 증가
void push(QueueType *Q, int n)
{
	if (full(Q)) {
		return;
	}
	Q->data[++(Q->rear)] = n;
}

//front를 이동시켜서 빈공간으로 인식시킴
int pop(QueueType* Q)
{
	if (empty(Q))
	{
		return -1;
	}
	int n = Q->data[++(Q->front)];
	return n;
}