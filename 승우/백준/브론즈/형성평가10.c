#include <stdio.h>

int main() {
    char aa[3][5];
    int i, j;

    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            scanf(" %c", &aa[i][j]); 
        }
    }

    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            printf("%c", aa[i][j] + 32);
        }
        printf("\n");
    }

    return 0;
}