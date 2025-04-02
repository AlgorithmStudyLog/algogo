#include <stdio.h>

int main(){
    // n행 3열, 4행 n열은 합계
    int arr[5][3] = {0};

    // 입력받으면서 합계까지 구하기
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            scanf("%d", &arr[i][j]);
            arr[i][2] += arr[i][j]; // 가로 합계
            arr[4][j] += arr[i][j]; // 세로 합계
            arr[4][2] += arr[i][j]; // 전체 합계
        }
    }

    printf("\n");

    // 가로 평균 출력
    for(int i = 0; i < 4; i++){
        printf("%d ", arr[i][2]/2);
    }
    printf("\n");

    // 세로 평균 출력
    for(int i = 0; i < 2; i++){
        printf("%d ", arr[4][i]/4);
    }
    printf("\n");

    // 전체 평균 출력
    printf("%d", arr[4][2]/8);

	return 0;
}