#include <iostream>
// 양방향 큐
// 큐는 원래 입출력되는 방향이 하나뿐
// deque(덱)은 양방향으로 삽입 삭제 가능
#include <deque>
using namespace std;

int main() {
    deque<int> dq;
    int n;
    cin >> n;
        
    for (int i = n; i > 0; i--)
    {
        dq.push_front(i);
        for (int j = 0; j < i; j++) // 큐를 회전하는 for문
        {
            dq.push_front(dq.back()); // 큐의 제일 뒤에 있는 요소를 앞으로 이동시킴
            dq.pop_back();
        }
    }
    
    for (auto x : dq)
        cout << x << " ";
    return 0;
}

// 큐로만 구현한 것
//#include <iostream>
//#include <queue>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//
//    queue<int> q;
//
//    // 역순으로 1까지 처리
//    for (int i = n; i >= 1; --i) {
//        // 1) push_front(i) 구현: 큐에 i 추가 후 (L-1)회 회전
//        q.push(i);
//        int L = q.size();
//        for (int k = 0; k < L - 1; ++k) { // 회전하기
//            q.push(q.front());
//            q.pop();
//        }

//        // 2) 뒤에서 i장 옮기기 구현: 큐를 한꺼번에 i번 오른쪽 회전
//        L = q.size();                 // 현재 큐 길이 (L = n - i + 1)
//        int r = i % L;                // i번 회전의 순환 효과 최적화
//        if (r != 0) {
//            int moveFrontCount = L - r;  // 왼쪽으로 이동할 횟수 = L - (i mod L)
//            for (int k = 0; k < moveFrontCount; ++k) {
//                q.push(q.front());
//                q.pop();
//            }
//        }
//        // 이제 i 단계 완료, 다음 i-1로 반복
//    }
//
//    // 최종 큐에는 초기 카드 순서가 담겨 있음. 출력하기
//    while (!q.empty()) {
//        cout << q.front();
//        q.pop();
//        if (!q.empty()) cout << ' ';
//    }
//
//    return 0;
//}
