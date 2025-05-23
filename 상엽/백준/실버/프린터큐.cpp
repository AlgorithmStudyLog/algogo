// 프린터큐.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 100

typedef struct
{
	int data[SIZE];
	int front;
	int rear;
}QueueType;

QueueType Q;

void init(QueueType* Q)		//front, back reset
{
	Q->front = -1;
	Q->rear = -1;
}

bool empty(QueueType* Q);
bool full(QueueType* Q);

int size(QueueType* Q);

int front(QueueType* Q);
int back(QueueType* Q);

void push(QueueType* Q, int n);
void pushback(QueueType* Q, int n);
int popfront(QueueType* Q);
int popback(QueueType* Q);


int main(void)
{
	int t;			//test case
	int N, M, num;	//num = strength(1~9)
	int max = -1;
	int i, j;

	int print[SIZE] = { 0 };

	scanf("%d", &t);

	init(&Q);

	for (i = 0; i < t;i++)
	{
		scanf("%d %d", &N, &M);

		for (j = 0;j < N;j++) {
			push(&Q, num);
			if (max < front(&Q))
			{
				max = front(&Q);
			}
		}
	}

	i = 0;
	while (!empty(&Q))
	{
		if (front(&Q) != max) {
			push(&Q, popfront(&Q));
		}
		else
		{
			print[i] = popfront(&Q);
		}
		i++;
	}





}

bool empty(QueueType* Q)
{
	if (Q->front == Q->rear)
	{
		return true;
	}
	else return false;
}
bool full(QueueType* Q)
{
	if (Q->rear == SIZE - 1)
	{
		return true;
	}
	else return false;
}

int size(QueueType* Q)
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
void push(QueueType* Q, int n)
{
	if (full(Q)) {
		return;
	}
	Q->data[++(Q->rear)] = n;
}

void pushback(QueueType* Q, int n)
{
	if (full(Q))
	{
		return;
	}
	Q->data[--(Q->front)] = n;
}

//front를 이동시켜서 빈공간으로 인식시킴
int popfront(QueueType* Q)
{
	if (empty(Q))
	{
		return -1;
	}
	int n = Q->data[++(Q->front)];
	return n;
}

int popback(QueueType* Q)
{
	if (empty(Q))
	{
		return -1;
	}
	int n = Q->data[--(Q->rear)];
	return n;
}