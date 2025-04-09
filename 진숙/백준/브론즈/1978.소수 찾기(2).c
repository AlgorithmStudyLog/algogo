#include <stdio.h>
#include <math.h>

int main(){
    int n = 0;              // 입력받을 자연수 개수
    int cnt = 0;            // 소수의 개수
    int arr[100];           // 입력받은 자연수를 저장할 배열 (n<=100)

    // 입력 받기
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    // 소수 구하는 방법: 제곱근 활용하기 
    for(int i = 0; i < n; i++){
        if(arr[i] == 1) continue;   // 1은 소수가 아니므로

        double sq = sqrt(arr[i]);   // 제곱근 구하기
        int flag = 1;               // 소수가 맞으면 flag = 1

        // 약수 유무 확인하기
        for(int j = 2; j <= sq; j++){
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



/*
* n의 약수는 무조건 1~n의 제곱근 범위 안에 존재한다
* n의 제곱근을 기준으로 약수끼리의 곱은 대칭으로 존재한다
* 위와 같은 이유로 n의 제곱근 이하의 값까지만 확인을 하면 된다

(예1)
n = 18
sqrt(18) = 4.242...
1 2 3 [4.242] 6 9 18
*/