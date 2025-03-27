#include <stdio.h>
#include <string.h>

int main(void)
{
    int sum = 0;
    char str[15];
    scanf("%s", str);
    for(int i = 0; i < strlen(str); i++){
        switch(str[i]) {
            case 'A': case 'B': case 'C':
                sum += 3; break; 
            case 'D': case 'E': case 'F':
                sum += 4; break;
            case 'G': case 'H': case 'I':
                sum += 5; break;
            case 'J': case 'K': case 'L':
                sum += 6; break;
            case 'M': case 'N': case 'O':
                sum += 7; break;
            case 'P': case 'Q': case 'R': case 'S': 
                sum += 8; break;
            case 'T': case 'U': case 'V': 
                sum += 9; break;
            case 'W': case 'X': case 'Y': case 'Z':
                sum += 10; break;
            default:
                sum += 11; break;
            }
    }
    printf("%d\n",sum);
}



/*
1. 문자열(str)을 입력받는다 (문자열은 2보다 크거나 같고, 15보다 작거나 같다)
2. 입력받은 문자열의 문자를 하나씩 꺼내 숫자와 비교한다
    2-1. 문자에 맞는 숫자를 찾는다
        2(ABC) / 3(DEF) / 4(GHI) / 5(JKL)
        6(MNO) / 7(PQRS) / 8(TUV) / 9(WXYZ)
        A = 65, Z = 90
3. 해당하는 숫자에 2를 더해 숫자를 거는데 소요되는 시간을 확인한다
4. 문자마다 소요되는 시간을 구하고 합(sum)을 구한다
5. 구한 합(sum)을 출력한다
*/