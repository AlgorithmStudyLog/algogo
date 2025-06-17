#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int arr[501][501];
bool visited[501][501];
deque<int> dq;

void bfs(int x,int y)
{
    while(!dq.empty())
    {
        int temp = dq.front();
        dq.pop_front();
         
    }    

}

int main() {
    ios_base::sync_with_stdio(false); // C++ 스트림과 C 스트림의 동기화 비활성화
    cin.tie(NULL); // cin과 cout의 묶음(tie) 해제
    
    int count = 0;
    int size  = 0;

    int n, m;
    cin >> n >> m; 
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!visited[i][j] && arr[i][j] == 1)
            {
                visited[i][j] = true;
                bfs(i,j);
            }
        }
    }
}
