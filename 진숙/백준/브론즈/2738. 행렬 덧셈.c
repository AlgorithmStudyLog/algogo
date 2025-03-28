#include <stdio.h>

int main(void){
    int row = 0, col = 0;

    scanf("%d %d", &row, &col);

    int arr1[row][col], arr2[row][col];
    int result[row][col];

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &arr1[i][j]);
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &arr2[i][j]);
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            result[i][j] = arr1[i][j] + arr2[i][j];
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }

    return 0;
}



/*
1. 2차원 배열의 행(row), 열(col)의 개수를 입력받는다
2. 2차원 배열을 2개 입력받는다(arr1,arr2)
    2-1. 행을 row번 입력받기 위해 반복문을 사용한다
    2-2. 행 1개당 col개의 열을 가지므로, 행 1개마다 col번 입력받기 위한 반복문을 사용한다
3. 2차원 배열 2개를 더한다(arr1,arr2)
    3-1. 결과를 저장할 result[row][col]를 만든다
    3-2. 이중 for문을 사용해 arr1[i][j] + arr2[i][j]의 값을 result[i][j]에 저장한다
4.  이중 for문을 사용해 result에 저장된 값을 출력한다
*/