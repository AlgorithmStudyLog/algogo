// typedef = 기존 자료형에 새 이름을 붙여서 간단하게 표현하는 함수
// ※ typedf int element --> element x = 10; 같은 느낌

// struct = 구조체를 한 덩어리로 묶어주는 함수
// ※ struct Student s1 = {"Alice", 20, 165.5} 
// printf("이름 %s \n", s1. name) 이런 느낌

// strcm = 두개의 문자열 비교 함수


#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 10000 // 문제와 동일하게 사이즈 10,000으로 지정

int stack[MAX_STACK_SIZE]; // 정수 저장 배열
int top = -1; // 스택의 맨 위 위치를 알려주는 변수
char command[10]; // 전역함수로 지정, 문자열 비교에 사용

// 스택에 정수 x 추가
void push(int x) {

    stack[++top] = x; // top을 먼저 증가 후, 증가 된 위치를 x에 저장
    /*
    top = -1;
    push(5);  // stack[0] = 5
    */
}

// 맨위의 숫자를 꺼냄 (지워짐)
int pop() {

    if (top == -1) return -1; // 스택이 비었으면 -1을 반환
    return stack[top--]; // -1을 반환
    /*
    stack[0] = 5, top = 0
    pop();  // 5를 반환하고, top = -1로 줄어듬
    */
}

// 몇개 있는지 알려줌
int size() {

    return top + 1; // 스택에 몇개의 데이터가 있는지 알려주는 수식 = top [0] = 1 / top [1] = 2
}

// 비었는지 확인 (1이면 비었다는 의미)
int empty() {

    return top == -1 ? 1 : 0; // top == -1 이면 비었으니 1로 출력 / 그렇지 않으면 0
}

// 최상단 정수 반환 -> 어떤 숫자가 있는지 체크 (지우지 않음)
int element() {

    if (top == -1) return -1; // 스택이 비었으면 -1을 주고, 존재한다면 맨 위 숫자를 보여줌
    return stack[top]; // 스택에 top 값을 반환
}

int main() {
    int N;
    scanf("%d", &N);

    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", command); // 매번 전역 함수 배열 command에 입력 받음

        if (strcmp(command, "push") == 0) {
            scanf("%d", &x);
            push(x); // 입력 값이 push 문자이면, x를 입력 받는다.
        }
        else if (strcmp(command, "pop") == 0) {
            // command와 pop 문자를 비교하여, 동일한 문자가 나오면 pop함수 실행
            printf("%d \n", pop());
        }
        else if (strcmp(command, "size") == 0) {
            // command와 size 문자를 비교하여, 동일한 문자가 나오면 size함수 실행
            printf("%d \n", size());
        }
        else if (strcmp(command, "empty") == 0) {
            // command와 empty 문자를 비교하여, 동일한 문자가 나오면 empty함수 실행
            printf("%d \n", empty());
        }
        else if (strcmp(command, "top") == 0) {
            // command와 top 문자를 비교하여, 동일한 문자가 나오면 elemnt함수 실행
            printf("%d \n", element());
        }
    }

    return 0;
}


/*
스택 문제 흐름도

1. 정수형 배열 stack[10000] 선언
2. top 값을 -1로 초기화
3. 문자열 저장할 command[10] 선언

4. 명령어 개수 N을 입력받음

5. N번 반복하면서 다음 작업을 수행:
    5-1 command(문자열)을 입력받음

    5-2 만약 command가 "push"라면:
        - 정수 x를 입력받고
        - 스택에 push(x)를 실행

    5-3 만약 command가 "pop"이라면:
        - 스택에서 숫자 꺼내고 출력 (없으면 -1 출력)

    5-4 만약 command가 "size"라면:
        - 스택에 있는 데이터 개수를 출력

    5-5 만약 command가 "empty"라면:
        - 스택이 비었는지 확인하고 결과 출력 (1: 비었음, 0: 아님)

    5-6 만약 command가 "top"이라면:
        - 스택 맨 위 숫자를 확인해서 출력 (없으면 -1)

6. 프로그램 종료


*/
