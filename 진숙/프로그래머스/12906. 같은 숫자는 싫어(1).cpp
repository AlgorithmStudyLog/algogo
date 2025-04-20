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
