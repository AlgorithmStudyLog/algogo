#include <stdio.h>

int main(){
    int n = 0;              // 입력받을 자연수 개수
    int cnt = 0;            // 소수의 개수
    int arr[100];           // 입력받은 자연수를 저장할 배열 (n<=100)

    // 입력 받기
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++){
        if(arr[i] == 1) continue;   // 1은 소수가 아니므로
        int flag = 1;               // 소수가 맞으면 flag = 1

        // 약수 유무 확인하기
        for(int j = 2; j < arr[i]; j++){
            if(arr[i] % j == 0){
                flag = 0;
                break;
            }
        }

        // 소수가 맞으면 소수 개수+1
        if(flag) cnt++;
    }

    // 출력
    printf("%d", cnt);
    return 0;
}