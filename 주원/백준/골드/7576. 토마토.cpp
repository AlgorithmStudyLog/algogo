#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int arr[1001][1001];
bool visited[1001][1001] = { false, };

deque<pair<int, int>> dq;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int date = -1;
int n, m;

// 미로탐색과 bfs알고리즘는 동일
void bfs()
{
    while (!dq.empty())
    {
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();

        for (int i = 0;i < 4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if (arr[nx][ny] == 0 && !visited[nx][ny])
                {

                    arr[nx][ny] = arr[x][y] + 1;
                    dq.push_back({ nx,ny });
                    visited[nx][ny] = true;

                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++ 스트림과 C 스트림의 동기화 비활성화
    cin.tie(NULL); // cin과 cout의 묶음(tie) 해제
    cin >> m >> n;

    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
            cin >> arr[i][j];
    }

    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (arr[i][j] == 1 && !visited[i][j]) // 시작 위치가 특정되지 않았기에 먼저 찾는다.
            {
                dq.push_back({ i,j });
                visited[i][j] = true;
            }
        }
    }
    bfs();

    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (arr[i][j] == 0) // bfs를 돌았는데 0이 남았다면 -1로 둘러싸여 가지 못하는곳
            {
                cout << -1;
                return 0; // 바로 종료
            }
            date = max(arr[i][j], date); // 최대 날짜를 비교하기 위해 
        }
    }
    cout << date - 1;

}
