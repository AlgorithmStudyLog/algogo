#include <stdio.h>
#define SORT(a, b) {int temp = a; a = b; b = temp;}

int main(){
    int arr[5] = {10, 40, 30, 60, 30};
    int sum = 0;

    for(int i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    for(int i = 0; i < 4; i++){
        for(int j = i+1; j < 5; j++){
            if(arr[i] > arr[j]) SORT(arr[i], arr[j]);
        }
    }

    printf("%d\n", sum / 5);
    printf("%d", arr[2]);

    return 0;
}