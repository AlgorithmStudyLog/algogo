#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int solution(int findIdx, int n, deque<int> dq, deque<int> iq, vector<int> v);
int main(){

    int caseCnt;
    scanf("%d", &caseCnt);

    for(int i = 0; i < caseCnt; i++){
        int n, findIdx;
        scanf("%d %d", &n, &findIdx);

        deque<int> dq;  
        deque<int> iq;  // dq의 인덱스를 담아둘 deque
        vector<int> v;  // dq의 값을 내림차순으로 정렬하고, max를 꺼내기위한 벡터

        // 입력받기
        for(int i = 0; i < n; i++){
            int value;
            cin >> value;

            v.push_back(value);
            dq.push_back(value);        
            iq.push_back(i);        
        }

        // vector 내림차순 정렬
        sort(v.rbegin(), v.rend());
        
        // 확인 결과 출력하기
        cout << solution(findIdx, n, dq, iq, v) << endl;
    }

    return 0;
}

int solution(int findIdx, int n, deque<int> dq, deque<int> iq, vector<int> v){
    int printOrder = 0; // 출력 순서를 담기 위한 변수

    for(int i = 0; i < n; i++){
        int max = v[i]; // v의 i번째 값으로 max를 초기화

        // dq의 front가 max일때까지 반복
        while(dq.front() != max){
            // max가 아니라면 front를 push_back하기
            dq.push_back(dq.front());
            iq.push_back(iq.front());
            // pop하기
            dq.pop_front();
            iq.pop_front();
        } 

        // 출력 순서 +1
        printOrder++;

        // iq에서 인덱스 확인하고 맞으면 반복 종료
        if(findIdx == iq.front()) break;

        // max와 같은 값을 삭제하기
        dq.pop_front();
        iq.pop_front();
    }
    return printOrder;
}

/*
0. 입력을 받는다
    n = 문서의 개수
    findIdx = 출력 순서를 확인할 문서의 최초 위치
1. n번 입력받고 확인 한다
    1. 입력받은 값을 아래 3개 컨테이너에 담는다
        deque   dq  
        deque   iq  최초 dq의 index를 기억하기위한 deque 
        vector  v   내림차순 정렬해서 max를 확인하기위한 vector
    2. v를 내림차순 정렬한다  
    3. n만큼 반복하면서 확인(solution 함수)
        3-1. v의 i번째 값으로 max를 초기화한다
        3-2. dq의 front와 max가 같은 값이 아니라면 아래 과정 반복. 같다면 2-3
            3-2-1. dq, iq에서 front를 push_back
            3-2-2. dq, iq에서 pop_front
        3-3. dq의 front와 max가 같은 값이면 반복 종료
        3-4. max를 찾았으므로 출력순서에 해당하는 변수 printOrder +1
        3-5. findIdx와 max와 같은 값의 최초 index(iq.front())가 동일하면 break. 아니라면 2-6
        3-6. dq, iq에서 pop_front
    4. printOrder 출력하기
*/