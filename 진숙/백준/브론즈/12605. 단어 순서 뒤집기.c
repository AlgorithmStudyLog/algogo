#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 30

void solution(char str[], int cnt);
void printReverse(char word[], int idx);

int main(){
    int n = 0;
    char str[SIZE];
    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++){
        scanf("%[^\n]s", str);
        getchar();
        solution(str, i+1);
    }
    return 0;
}

void solution(char str[], int cnt){
    int idx = 0;
    char word[SIZE];
    int len = strlen(str);

    printf("Case #%d: ", cnt);

    for(int i = len-1; i >= 0; i--){
        if(!isspace(str[i])){
            word[idx++] = str[i];
            continue;
        }
        printReverse(word, idx);
        printf(" ");
        idx = 0;
    }
    printReverse(word, idx);
    printf("\n");
}

void printReverse(char word[], int idx){
    for(int j = idx-1; j >= 0; j--){
        printf("%c", word[j]);
    }
}