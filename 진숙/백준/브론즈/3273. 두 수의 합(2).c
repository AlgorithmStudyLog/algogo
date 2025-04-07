#include <stdio.h>
#include <stdlib.h>

// 비교 함수: 오름차순 정렬
int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int main(){
    int n = 0;                  // 수열의 크기 = 배열의 크기
    int x = 0;                  // ai + aj = x 의 기준이 될 x 값
    int cnt = 0;                // 쌍의 개수를 저장할 변수
    int arr[1000001];

    // 입력 받기
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);   // 입력 받는다
    }   
    scanf("%d", &x);

    // 퀵 정렬 사용(다른 정렬은 시간 초과..)
    qsort(arr, n, sizeof(int), compare);

    // 확인하기
    int left = 0, right = n - 1;
    while(left < right){
        int temp = arr[left] + arr[right];
        if(temp == x){
            cnt++;
            left++;
            right--;
        }else if(temp < x){
            left++;
        }else{
            right--;
        }
    }

    // 출력하기
    printf("%d", cnt);
    return 0;
}
