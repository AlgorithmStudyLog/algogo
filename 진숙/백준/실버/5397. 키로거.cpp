#include <iostream>
#include <list>

using namespace std;
int main(){
    int caseCnt;
    cin >> caseCnt;

    for(int i = 0; i < caseCnt; i++){
        list<char> left;
        list<char> right;
        string testCase;

        cin >> testCase;

        for(char c: testCase){
            switch (c)
            {
            case '<':
                if(left.empty()) break;
                right.push_front(left.back());
                left.pop_back();
                break;
            
            case '>':
                if(right.empty()) break;
                left.push_back(right.front());
                right.pop_front();
                break;
            
            case '-':
                if(left.empty()) break;
                left.pop_back();
                break;

            default:
                left.push_back(c);
            }
        }   
        for(auto c: left){
            cout << c;
        }
        for(auto c: right){
            cout << c;
        }
        cout << endl;
    }
}