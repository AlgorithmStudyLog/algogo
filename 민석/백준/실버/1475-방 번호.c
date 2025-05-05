#include <stdio.h>
#include <string.h> // 문자열 함수
#include <math.h> // 수학 함수

#define MAX 10000

// 전역 큐 선언
char queue[MAX]; // 문자형 Q 배열
int front = 0; // 큐를 빼내는 함수 [맨앞]
int rear = 0; // 큐를 삽입하는 함수 [맨뒤]

void enqueue(char date) // 큐에서 데이터 넣기
{
	if (rear >= MAX) // 큐가 가득찼는지 확인
	{
		return;
	}
	queue[rear++] = date; // 끝 위치를 한칸 이동
}

char dequeue() // 큐에서 데이터 꺼내기
{
	if (front == rear) // 큐가 비었으면 출력
	{
		return -1; // -1 값을 반환
	}
	return queue[front++]; // 꺼낼 위치를 다음 칸으로 이동
}

int is_empty() // 큐가 비었는지 확인
{
	return front == rear;
}

int main() 
{
	char room[MAX]; // 방번호 지정 문자열
	int count[10] = { 0 }; // 0 ~ 9까지 각각 몇번 나갔는지 저장하는 배열

	scanf("%s", room);

	for (int i = 0; i < strlen(room); i++) // 문자 하나씩 Q에 저장
	{
		enqueue(room[i]); // room 길이만큼 반복
	}

	while (!is_empty()) 
	{
		char ch = dequeue(); // 데이터 꺼내기
		int digit = ch - '0';  // 문자를 숫자로 변환
		count[digit]++; // 등장 횟수를 배열로 기록
	}

	int six_nine = count[6] + count[9]; // 6, 9를 함께 사용 가능함으로 합쳐서 처리
	count[6] = count[9] = (int)ceil(six_nine / 2.0); // 합친 수를 2로 나누고 올림 - ceil

	int max = 0;
	for (int i = 0; i < 10; i++) 
	{
		if (count[i] > max)
			max = count[i]; // 가장 많이 필요한 갯수를 세트에 저장
	}

	printf("%d\n", max);

	return 0;
}
