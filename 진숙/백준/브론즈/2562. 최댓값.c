#include <stdio.h>
#include <string.h>

int main(void){
    int arr[9];
    int max = 0, idx = 0;
    for(int i = 0; i < 9; i++){
        scanf("%d", &arr[i]);
        if(arr[i] > max){
            max = arr[i];
            idx = i;
        }
    }

    printf("%d\n%d", arr[idx], idx+1);
    return 0;
}

/*
1. 9개의 자연수를 입력받는다 (배열 arr에 담는다)
2. 최댓값을 저장할 변수(max)를 선언한다
    2-1. 저장하는 값이 자연수 이므로, 0으로 초기화한다
3. 최댓값의 인덱스를 저장할 변수(idx)를 선언한다
4. 최댓값을 구한다
    4-1. for문에서 변수 i를 사용해 반복하며 배열 arr의 요소를 하나씩 꺼낸다
    4-2. max 와 비교하고 arr[i]의 값이 max보다 큰 경우
        4-2-1. max에 arr[i]를 대입한다
        4-2-2. idx에 i 를 대입한다.
5. 최댓값과 몇 번째 수인지 출력한다
*/