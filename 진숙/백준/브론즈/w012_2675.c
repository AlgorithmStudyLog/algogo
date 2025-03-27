#include <stdio.h>
#include <string.h>

int main(){
    int t = 0; // 테스트 케이스 개수
    int r = 0; // 문자를 반복할 횟수
    char s[20];

    scanf("%d", &t);
    

    for(int i = 0; i < t; i++){
        scanf("%d %s", &r, s);
        for(int j = 0; j < strlen(s); j++){
            for(int k = 0; k < r; k++){
                printf("%c", s[j]);
            }
        }
        printf("\n");
    }   
    return 0;
}



/*
1. 몇 개의 테스트케이스(t)를 확인할지 입력받는다
2. 테스트케이스를 입력받는다
    2-1. 문자를 몇 번 반복할지 입력받는다(r)
    2-2. 어떤 문자열을 반복할지 입력받는다(s)
3. 문자열의 문자를 하나씩 꺼낸다
    3-1. 꺼낸 문자를 r번 반복해서 출력한다
4. t만큼 2~3번의 행동을 반복한다
*/