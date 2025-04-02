#include <stdio.h>
#include <ctype.h>

int main(){
    char arr[3][5];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            scanf(" %c", &arr[i][j]);
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            printf("%c ", tolower(arr[i][j]));
            //printf("%c ", arr[i][j]+32); // 'A' + 32 = 'a'
        }
        printf("\n");
    }

	return 0;
}


