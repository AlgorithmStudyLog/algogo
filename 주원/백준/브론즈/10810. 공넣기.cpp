#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n, m;
    // 처음 5 4 입력
    cin >> n >> m;
    // 먼저 arr을 초기화
    vector<int> arr(n+1, 0);

    for (int i = 0;i < m;i++) {
        // 2번째 줄부터 입력
        int a, b, c;
        cin >> a >> b >> c;
        // a~b까지 c번 공을 넣는다.
        // 이때 조건에 이미 공이 있다면 빼고 넣으라고 했지만, 
        // 새로운 값을 대입하면 기존 값이 삭제 되기에 
        // 굳이 추가적인 연산을 안해도 된다.
        for (int j = a;j <= b;j++) {
            
            arr[j] = c;
        }
            
    }

    for (int i = 1;i < arr.size();i++)
        cout << arr[i] << " ";
}