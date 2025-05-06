#include <stdio.h>
#include <string.h>

int main(){
    int arr[9] = {0};   // 사용된 숫자 확인하기위한 배열 (0~8) , 9인 경우 입력된 경우 6을+1한다
    char num[10];       // 1,000,000보다 작거나 같은 자연수
    scanf("%s", num);
    getchar();

    int len = strlen(num);
    for(int i = 0; i < len; i++){
        int idx = num[i] - '0';
        if(idx == 9 || idx == 6) arr[6]++;
        else arr[idx]++;
    }

    int maxCnt = 0;
    if(arr[6] % 2 != 0) arr[6]++;
    arr[6] /= 2;
    for(int i = 0; i < 9; i++){
        if(maxCnt < arr[i]){
            maxCnt = arr[i];
        }
    }

    printf("%d", maxCnt);

    return 0;
}