#include <stdio.h>
#include <stdlib.h> // atoi()를 사용하기위함
#include <string.h>

// 사용자 함수 reverse_to_int 선언 
int reverse_to_int(char str[]);

int main(){
    char str1[4], str2[4]; // 처음 입력값 (세자리 정수 + \0)
    int n1 = 0, n2 = 0; // 변경값

    scanf("%s %s", str1, str2);

    n1 = reverse_to_int(str1);
    n2 = reverse_to_int(str2);

    if(n1 > n2){
        printf("%d", n1);
    }else{
        printf("%d", n2);
    }

    return 0;
}


// 사용자 함수 reverse_to_int 정의
reverse_to_int(char str[]){
    int size = strlen(str);     // 매개변수로 받아온 문자열의 길이
    char reversed_str[size];    // 뒤집은 문자열을 저장할 문자열
    for(int i = 0; i < size; i++){  // 문자열 뒤집기
        reversed_str[i] = str[size-i-1];
    }
    return atoi(reversed_str);  
}


/*
0. 문자열을 사용한 풀이 | atoi()
1. 문자열을 2개(str1,str2) 입력받는다
2. 문자열을 뒤집어 저장한다
3. 뒤집은 문자열을 정수형으로 변환시킨다 | atoi() | <stdlib.h> 
    * atoi() = Ascii TO Integer
    * atoi(문자열) -> 정수 로 바꾸어주는 함수
    * atoi() 는 매개변수로 받은 값이 문자열에 숫자가 아닌 다른 문자가 포함되어 있으면 변환을 중단하고, 변환 가능한 부분까지만 숫자로 반환
    * strtoi() = STRing to Long
    * atoi()와 동일하게 문자열을 정수로 변환시켜주는 함수. atoi()보다 오류 처리가 더 상세하다.
4. 변환된 값(n1,n2)을 비교한다
    4-1. res1 > res2 인 경우 res1 출력
    4-2. res1 < res2 인 경우 res2 출력
*/