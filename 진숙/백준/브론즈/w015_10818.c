#include <stdio.h>

int main(void){
    int cnt = 0;
    int min = 1000000, max = -1000000;

    scanf("%d", &cnt);

    int arr[cnt];
    for(int i = 0; i < cnt; i++){
        scanf("%d", &arr[i]);
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }

    printf("%d %d", min, max);
    return 0;
}



/*
1. 정수의 개수(cnt)를 입력받는다
2. 비교를 위한 변수를 선언한다
    2-1. 최소값을 저장할 변수 min > 범위 내 최대값 1,000,000
    2-2. 최대값을 저장할 변수 max > 범위 내 최소값 -1,000,000
2. 정수를 입력받는다 
    3-2. 정수가 min보다 작은지 확인한다
        3-2-1. 참이면 min에 대입
    3-3. 정수가 max보다 큰지 확인한다
        3-3-1. 참이면 max에 대입
3. 2번의 과정을 cnt번 반복한다 
4. 최소값과 최대값을 출력한다 
*/