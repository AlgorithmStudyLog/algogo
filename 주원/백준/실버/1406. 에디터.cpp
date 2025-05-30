#include <iostream>
#include <list>

using namespace std;

int main() {

    // 커서 : 앞 뒤 중간에 존재
    //문자 길이 L이라면 L+1까지 갈 수 있음
    // L: 왼쪽(맨앞이라면 무시) / D 오른쪽 이동 / B 왼쪽 문자 삭제 (커서 위치 그대로) / P $ : "$"라는 문자 왼쪽에 추가 ->

    
    string n;
    cin >> n;
    list<char> arr(n.begin(),n.end());
    
    int m;
    cin >> m;

    auto cursor = arr.end(); // list에서 인덱스를 다루기 위해 iterator 형을 사용해야 됨. -> auto로 자동으로 맞춰줌

    for (int i = 0;i < m;i++)
    {
        char ch;
        cin >> ch;
        if (ch == 'P')
        {
            char ch;
            cin >> ch;
            arr.insert(cursor, ch); // 커서 위치에 삽입
            
        }
        else if (ch == 'L')
        {
            
            if (cursor != arr.begin()) // 0 이하로 된다면 0으로 맞추기 위해서 조건 설정
                cursor--;

        }
        else if (ch == 'D')
        {
            
            if (cursor != arr.end()) // list 크기보다 큰 경우를 해결하기 위한 조건
                cursor++;
        }
        else if (ch == 'B')
        {
            if (cursor != arr.begin()) //삭제하기
            {
                cursor = arr.erase(--cursor);
            }

        }
    }
    for(auto a : arr)
    {
       cout << a;
    }
    return 0;
}

// #include <iostream>
// #include <deque>

// using namespace std;

// int main() {

//     // 커서 : 앞 뒤 중간에 존재
//     //문자 길이 L이라면 L+1까지 갈 수 있음
//     // L: 왼쪽(맨앞이라면 무시) / D 오른쪽 이동 / B 왼쪽 문자 삭제 (커서 위치 그대로) / P $ : "$"라는 문자 왼쪽에 추가 ->

//     string n;
//     cin >> n;
//     int m;
//     cin >> m;

//     int cursor = n.length();

//     for (int i = 0;i < m;i++)
//     {
//         char ch;
//         cin >> ch;
//         if (ch == 'P')
//         {
            
//             if (cursor >= n.length())
//             {
//                 char temp;
//                 cin >> temp;
//                 n.push_back(temp);
//                 cursor = n.length();
//             }
//             else
//             {
//                 string temp;
//                 cin >> temp;
//                 n.insert(cursor, temp);
//                 cursor++;
//             }
            
//         }
//         else if (ch == 'L')
//         {
//             cursor--;
//             if (cursor < 0)
//                 cursor = 0;

//         }
//         else if (ch == 'D')
//         {
//             cursor++;
//             if (cursor > n.length())
//                 cursor = n.length();
//         }
//         else if (ch == 'B')
//         {
//             if (cursor > 0)
//             {
//                 n.erase(cursor - 1, 1);
//                 cursor--;
//             }

//         }
//     }
//     cout << n;
//     return 0;
// }
