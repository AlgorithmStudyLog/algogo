#include <iostream>

using namespace std;

long long solution(long long a, long long b, long long c) {
    // b가 0이면 A^0 은 1이고, c로 나눈 나머지도 1이니까 return 1
    if (b == 0) return 1; 

    // b가 1이 아니면
    long long half = solution(a, b / 2, c); // 반으로 나눠서 재귀(분할)
    long long result = (half * half) % c;   // 짝수 처리
    if (b % 2 == 1) result = (result * a) % c;  // 홀수 처리
    return result;
}


int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    cout << solution(a, b, c) << '\n';
    return 0;
}

// https://deepdata.tistory.com/369
/*
A^8 = A^4 * A^4 = (A^4)^2 = ((A^2)^2)^2
B가 짝수면 반으로 나누고 제곱
B가 홀수면 반으로 나눈거 제곱하고, 한번 더 곱한다
*/