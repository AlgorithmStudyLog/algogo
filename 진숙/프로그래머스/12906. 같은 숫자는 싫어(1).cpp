#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    // vector 사용 방법
    // 1. vector 길이 선언하지 않고, 인덱스로 대입 X push_back() O
    // 2. vector 길이 선언하고, 인덱스로 대입 O push_back() X
    //  *길이 선언하면 무조건 0으로 모두 초기화됨
    
    int temp = arr[0];
    answer.push_back(arr[0]);
    for(int i = 1; i < arr.size(); i++){
        if(temp == arr[i]){
            continue;
        }else{
            temp = arr[i];
            answer.push_back(arr[i]);
        }
    }
    
    return answer;
}

/*
auto it = unique(vec.begin(), vec.end());
vec.erase(it, vec.end());

1. auto 타입
auto는 C++11에서 도입된 키워드로, 변수의 타입을 컴파일러가 자동으로 추론
auto는 초기화된 값으로만 타입을 추론하므로 반드시 선언과 함께 초기화 해야한다 

2. unique(시작위치, 끝위치)
<algorithm> 헤더에 포함된 연속된 중복 값들 중 하나만 남기고 나머지는 제거해주는 함수
unique()는 크기를 줄이지 않음. 원래 vector의 길이를 유지
중복 값은 덮어쓰기만 하고, 반환되는 이터레이터(iterator)는 마지막 고유 값의 다음 위치를 가리킴
반환받은 이터레이터를 활용, erase()로 크기를 줄여줘야한다 
    2-1. 이터레이터(Iterator): 컨테이너(vector, list, map 등)를 반복하면서 하나씩 접근하는 방법
    2-2. 컨테이너(Containers): 데이터를 저장하는데 사용되는 데이터 구조 
            vector: 동적 배열
            list: 연결 리스트
            deque: 양쪽 끝에서 삽입/삭제가 가능한 큐
            set: 중복되지 않는 값들을 저장하는 집합
            map: 키-값 쌍을 저장하는 연관 배열
    2-3. vector.begin() 시작위치, vector.end() 끝위치

3. 연속적인 컨테이너.erase(시작위치, 끝위치)
연속적인 컨테이너의 시작위치-끝위치의 요소를 삭제하고 크기를 조잘한다
하나의 값만 지울때는 하나의 위치만 인자에 넣는다
    3-1. 연속적 컨테이너의 특징
            메모리 연속성: 요소들이 메모리 상에 연속적으로 배치
            임의 접근 가능: 인덱스를 통해 바로 접근할 수 있는 특성
    3-2. 컨테이너 구분
            [연속적인 컨테이너]     [비연속적인 컨테이너]
            vector              stack
            deque               queue
            list                priority_queue
            set                 array
            map
            unordred_set
            unordred_map
*/