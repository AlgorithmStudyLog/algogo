#include <stdio.h>
#include <string.h>

int main(){
    int n1 = 0, n2 = 0; // 처음 입력값
    int res1 = 0, res2 = 0; // 변경값

    scanf("%d %d", &n1, &n2);

    res1 = (n1%10)*100 + ((n1%100)/10)*10 + (n1/100); 
    res2 = (n2%10)*100 + ((n2%100)/10)*10 + (n2/100); 

    if(res1 > res2){
        printf("%d", res1);
    }else{
        printf("%d", res2);
    }

    return 0;
}



/*
0. 정수를 사용한 풀이
1. 정수 2개(n1,n2)를 입력받는다
2. 입력받은 정수를 뒤집어 저장한다
    2-1. 입력받은 정수의 일의 자리를 백의 자리로 옮긴다
        2-1-1. 정수를 10으로 나누었을 때 나머지를 구한다 (예) 123 / 10 = 12 ... 3 
        2-1-2. 이는 곧 입력받은 정수의 일의 자리 값 (예) 123 -> ##3 
        2-1-3. 백의 자리로 옮겨주어야하기때문에 x 100 한다 (예) 3 * 100 = 300
    2-2. 입력받은 정수의 십의 자리를 십의 자리로 옮긴다(유지한다)
        2-2-1. 정수를 100으로 나머지를 구한다 (예) 123 / 100 = 1 ... 23
        2-2-2. 나머지를 10으로 나눈 값이 입력받은 정수의 십의 자리 값 (예) 23 / 10 = 2 
        2-2-3. 십의 자리로 유지해야하기때문에 x 10 한다 (예) 2 x 10 = 20
    2-3. 입력받은 정수의 백의 자리를 일의 자리로 옮긴다
        2-3-1. 정수를 100으로 나눈 몫을 구한다 (예) 123 / 100 = 1
        2-3-2. 이는 곧 백의 자리 수인데, 일의 자리수가 되어야하므로 그대로 사용한다
3. 입력받은 정수 2개(n1,n2)에 2번의 행동을 실행해 정수를 뒤집어 각각 res1, res2에 저장한다
4. res1과 res2를 비교한다
    4-1. res1 > res2 인 경우 res1 출력
    4-2. res1 < res2 인 경우 res2 출력
*/