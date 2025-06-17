#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int arr[501][501];  // 그림의 전체 크기
bool visited[501][501] = {false,}; // 방문을 확인하기 위한 배열
deque<pair<int, int>> dq; // (x,y) 좌표처럼 사용하기 위해 pair를 사용

int nx[4] = { 1,0,-1,0 }; // 그림의 좌우를 체크하기 위한 변수
int ny[4] = { 0,1,0,-1 }; // 그림의 상하를 체크하기 위한 변수
int n, m; // 그림의 크기


int bfs(int a, int b)
{
    int result = 1; // 햔제 그림의 크기를 저장하기 위한 변수, 1로 초기화하는 이유는 해당 위치에서 시작을 하니까
    dq.push_back({ a,b }); // 덱에 저장한다.

    while (!dq.empty()) // 더이상 1로 갈 수 없을때까지 반복
    {
        int x = dq.front().first; // x 좌표
        int y = dq.front().second; // y 좌표

        dq.pop_front();

        for (int i = 0;i < 4;i++) // 상하좌우를 탐색하기 위해서
        {
            int dx = x + nx[i]; // 현재 위치(x 좌표)에서 상하를 판별
            int dy = y + ny[i]; // 현재 위치(y 좌표)에서 좌우를 판별
            if (0 <= dx && dx < n && 0 <= dy && dy < m) // 다음 이동할 위치가 그림의 최대 크기를 넘지 않는다면
            {
                if (arr[dx][dy] == 1 && visited[dx][dy] == false) // 다음 위치가 그려져있다면 (1) && 아직 방문하지 않았다면
                {
                    result++; // 그림의 크기 증가
                    visited[dx][dy] = true; // 방문처리
                    dq.push_back({ dx,dy }); // 다음 위치를 저장
                }
            }
        }

    }
    return result;

}
int dfs(int a,int b)
{
    int result = 1; // 햔제 그림의 크기를 저장하기 위한 변수, 1로 초기화하는 이유는 해당 위치에서 시작을 하니까
    visited[a][b] = true;
    for (int i = 0;i < 4;i++) // 상하좌우를 탐색하기 위해서
        {
            int dx = a + nx[i]; // 현재 위치(x 좌표)에서 상하를 판별
            int dy = b + ny[i]; // 현재 위치(y 좌표)에서 좌우를 판별
            if (0 <= dx && dx < n && 0 <= dy && dy < m) // 다음 이동할 위치가 그림의 최대 크기를 넘지 않는다면
            {
                if (arr[dx][dy] == 1 && visited[dx][dy] == false) // 다음 위치가 그려져있다면 (1) && 아직 방문하지 않았다면
                {
                    visited[dx][dy] = true;
                    result += dfs(dx,dy);
                    
                }
            }
        }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); // C++ 스트림과 C 스트림의 동기화 비활성화
    cin.tie(NULL); // cin과 cout의 묶음(tie) 해제

    int count = 0; // 그림의 개수를 저장할 변수
    int size = 0; // 그림의 최대 크기를 저장할 변수

    cin >> n >> m;

    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            cin >> arr[i][j];
        }
    }

    // 전체 그림을 탐색하면서 로직 달성
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (!visited[i][j] && arr[i][j] == 1) // 아직 들리지 않은 그림이면서 그림이 그려져있다면(1이라면)
            {
                // bfs로 할 때
                // visited[i][j] = true; // 방문 true로 하기
                // count++; // 그림 개수 더하기
                // size = max(size, bfs(i, j)); // 그림의 최댓값 갱신
                
                // dfs로 할ㄷ 때
                count++;
                size = max(size,dfs(i,j));

            }
        }
    }

    cout << count << endl;
    cout << size << endl;
}
