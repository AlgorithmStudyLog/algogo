#include <stdio.h>

int main(){
    int arr[9][9];
    int max = 0;
    int max_i = 0, max_j = 0;

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            scanf("%d", &arr[i][j]);
            if(max < arr[i][j] || max == arr[i][j]){
                max = arr[i][j];
                max_i = i+1;
                max_j = j+1;
            }
        }
    }

    printf("%d\n", max);
    printf("%d %d", max_i, max_j);

    return 0;
}