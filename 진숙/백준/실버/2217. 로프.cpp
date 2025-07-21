#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> ropes;

    // 입력
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp = 0;
        cin >> temp;
        ropes.push_back(temp);
    }

    // 내림차순 정렬 
    sort(ropes.begin(), ropes.end()); 
    reverse(ropes.begin(), ropes.end());

    // 답 찾기
    int answer = 0;
    for(int i = 0; i < n; i++){
        int temp = ropes[i] * (i+1);
        if(answer < temp) answer = temp;
    }

    // 출력
    cout << answer;
    
    return 0;
}