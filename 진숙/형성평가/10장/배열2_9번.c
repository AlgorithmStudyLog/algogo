#include <stdio.h>

int main(){
    int arr[10][10] = {0};
    int size = 0;
    scanf("%d", &size);

    // 일반 파스칼 삼각형으로 만들고
    for(int i = 0; i < size; i++){
        for(int j = 0; j < i+1; j++){
            if(j == 0){
                arr[i][j] = 1;
            }else{
                arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
            }
        }
    }

    // 역으로 출력 
    for(int i = size-1; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
	return 0;
}


// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// 1 5 10 10 5 1