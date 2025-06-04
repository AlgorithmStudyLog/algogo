#include <iostream>
#include <list>

using namespace std;

int main() 
{
    // 입력이 (1 ≤ L ≤ 1,000,000) 이므로 매우 빠른 것을 선택해야됨. Ex) list
    // < , > 로 커서 위치 움직임
    // - : 왼쪽 글자 제거.
    int n;
    cin >> n;
    

    for (int i = 0;i < n;i++)
    {
        string str;
        cin >> str;
        list<char> arr;
        auto cursor = arr.begin();
        
        for (int j = 0;j < str.size();j++)
        {
            if (str[j] == '>')
            {
                if (cursor != arr.end())
                    cursor++;
            }
            else if (str[j] == '<')
            {
                if (cursor != arr.begin())
                {
                    cursor--;
                }
            }
            else if (str[j] == '-')
            {
                if (cursor != arr.begin())
                    cursor = arr.erase(--cursor);
            }
            else
            {
                cursor = arr.insert(cursor, str[j]);
                cursor++;
            }
        }

        for (auto a : arr)
        {
            cout << a;
        }
        cout << endl;
    }

    
}
