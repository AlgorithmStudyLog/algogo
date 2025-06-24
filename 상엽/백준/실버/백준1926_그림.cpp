#include <iostream>
#include <vector>
using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0 ,-1, 1 };

int main()
{
	int n, m, i, j;
	cin >> n >> m;
	
	vector<vector<int>>grid (n, vector<int>(m, 0));

	for (i = 0;i < n;i++)
	{
		for (j = 0;j < m;i++) {
			cin >> grid[i][j];
		}
	}

	cout << cnt(grid) << "\n";
	//cout << 

}

//grid : 그림 그리는 공간, bool : 방문 여부
void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited, int n, int m)
{
	visited[x][y] = true; //방문 지점을 true로 처리하여 중복하여 도달하지 않게 만듬

	int i;

	for (i = 0;i < 4;i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m)	//배열 안에서 트래킹
		{
			if (grid[nx][ny] == 1 && !visited[nx][ny])	// dx = 1, dy = 1 인 좌표값 추적
			{
				dfs(nx, ny, grid, visited, n, m);
			}
		}
	}
}

// 재귀함수 dfs를 계속 돌려서 끝나면 그림 하나로 간주
int cnt(vector<vector<int>>& grid)
{
	int n = grid.size();
	int m = grid[0].size();
	int count = 0;
	int i, j;

	vector<vector<bool>> visited(n, vector<bool>(m, false));

	for (i = 0;i < n;i++)
	{
		for (j = 0;j < m;j++)
		{
			if (grid[i][j] == 1 && !visited[i][j])
			{
				dfs(i, j, grid, visited, n, m);
				count++;
			}
		}
		return count;
	}
}