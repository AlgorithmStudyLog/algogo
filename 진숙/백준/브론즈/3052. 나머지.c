#include <stdio.h>
#define SIZE 42

int main(){

    // 나머지 값 사용 여부 확인할 배열
    // size가 42인 이유: 42로 나눴을 때 나머지의 최대값은 41이므로 (1~41) 을 활용하기 위함
    int arr[SIZE] = {0};
    int cnt = 0;    // 서로 다른 값이 몇 개인지 카운트하기위한 변수

    for(int i = 0; i < 10; i++){
        int n = 0;  // 입력받을 숫자 저장할 변수
        scanf("%d", &n);

        int idx = n % 42;
        if(arr[idx] == 0) arr[idx] = 1;
    }

    for(int i = 0; i < SIZE; i++){
        if(arr[i] == 1) cnt++;
    }

    printf("%d", cnt);
    return 0;
}
