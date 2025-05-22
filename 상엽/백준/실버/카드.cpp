// 카드.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
using namespace std;

#define SIZE 100

class Deque {
private:
	int data[SIZE];
	int front;
	int rear;

public:
	Deque() {
		front = 50;
		rear = 49;
	}

	bool empty() const {
		return front > rear;
	}

	bool full() const {
		return front == 0 && rear == SIZE - 1;
	}

	void pushFront(int n) {
		if (front - 1 < 0) return;
		data[--front] = n;
	}

	void pushBack(int n) {
		if (rear + 1 >= SIZE) return;
		data[++rear] = n;
	}

	int popFront() {
		if (empty()) return -1;
		return data[front++];
	}

	int popBack() {
		if (empty()) return -1;
		return data[rear--];
	}

	void print() const {
		for (int i = front; i <= rear; i++) {
			cout << data[i] << " ";
		}
	}
};

int main() {
	int n;
	cin >> n;

	Deque dq;

	for (int i = 4; i > 0; i--) {
		dq.pushFront(i);
		for (int j = 0; j < i; j++) {
			int a = dq.popBack();
			dq.pushFront(a);
		}
	}

	dq.print();

	return 0;
}




/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
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
	Q->front = 50;
	Q->rear = 49;
}

bool empty(QueueType* Q);
bool full(QueueType* Q);

void pushfront(QueueType* Q, int n);
void pushback(QueueType* Q, int n);
int popfront(QueueType* Q);
int popback(QueueType* Q);
void print(QueueType* Q);

int main(void)
{
	int n, i, j;
	int a;

	scanf("%d", &n);

	init(&Q);

	for (i = 4;i > 0;i--)
	{
		pushfront(&Q, i);
		for (j = 0; j < i;j++)
		{
			a = popback(&Q);
			pushfront(&Q, a);
		}
	}
	print(&Q);
	
	return 0;
}


bool empty(QueueType* Q)
{
	if (Q->front > Q->rear)
	{
		return true;
	}
	else return false;
}
bool full(QueueType* Q)
{
	if (Q->front == 0 && Q->rear == SIZE - 1)
	{
		return true;
	}
	else return false;
}
//값을 입력하면 rear값을 1올리고 push >>index번호 증가
void pushback(QueueType* Q, int n)
{
	if (full(Q)) {
		return;
	}
	Q->data[++(Q->rear)] = n;
}

void pushfront(QueueType* Q, int n)
{
	if (Q->front - 1 < 0)
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
	int n = Q->data[(Q->front)++];
	return n;
}

int popback(QueueType* Q)
{
	if (empty(Q))
	{
		return -1;
	}
	int n = Q->data[(Q->rear)--];
	return n;
}
void print(QueueType* Q)
{
	int i;
	for (i = Q->front;i <= Q->rear;i++)
	{
		printf("%d ", Q->data[i]);
	}
}*/

/*
행동을 역순으로

맨 처음 4 배치

3배치

34>43>34>43

2배치

243>324>432

1배치

1432 > 2143

2143 출력
*/