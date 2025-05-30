#include <iostream>
#include <list>

using namespace std;

void inputCommand(list<char> &left, list<char> &right);
void printList(list<char> l);

int main(){
    list<char> left;
    list<char> right;

    string initValue;
    cin >> initValue;

    for(char c : initValue){
        left.push_back(c);
    }

    // 명령어마다 수행
    inputCommand(left, right);

    // 출력 
    printList(left);
    printList(right);

    return 0;
}

void inputCommand(list<char> &left, list<char> &right){
    int cnt;
    cin >> cnt;    

    for(int i = 0; i < cnt; i++){
        char command;
        char c;

        cin >> command;
        
        switch (command)
        {
        case 'L':
            // left가 비어있지 않을 때 (비어있다면 커서가 문장의 맨 앞이므로)
            if(left.size() != 0){
                // left의 마지막 요소를 right[0]으로 삽입
                right.push_front(left.back());

                // left에서 삭제
                left.pop_back();
            }
            break;
        case 'D':
            // right가 비어있지 않을 때 (비어있다면 커서가 문장의 맨 뒤이므로)
            if(right.size() != 0){
                // right[0] 을 left에 push_back
                left.push_back(right.front());

                // right[0] 을 리스트에서 제거
                right.pop_front();
            }
            break;
        case 'B':
            // left가 비어있지 않을 때
            if(left.size() != 0){
                // left의 마지막 요소를 삭제
                left.pop_back();
            }
            break;
        case 'P':
            cin >> c;
            left.push_back(c);
            break;        
        default:
            break;
        }
    }
}


void printList(list<char> l){
    for(char c: l){
        cout << c;
    }
}


/*
커서 왼쪽 리스트, 오른쪽 리스트 필요
left는 단일 연결 리스트면 충분
right는 이중 연결 리스트 필요(앞에 값을 삽입해야하므로

cpp에서 list는 이중 연결 리스트로 구현되어 있어서 활용하기
*/