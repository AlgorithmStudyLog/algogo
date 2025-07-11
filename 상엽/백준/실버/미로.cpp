// 미로.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0 ,-1, 1 };

int main()
{



}




//지점 찾기
void difroot(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited, int n, int m, char (*array)[100])
{
    visited[x][y] = true;

    int i;

	for (i = 0;i < 4;i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m)
		{
			if (grid[nx][ny] == 1 && !visited[nx][ny])
			{
				if (dx[i] == 1 && dy[i] == 0)
				{
					array[nx][ny] << 'R';
					if (array[x][y] != 1 && array[nx][ny] != array[x][y])
					{
						array[nx][ny] == 1;
					}
					difroot(nx, ny, grid, visited, n, m, (*array)[100]);
				}

				if (dx[i] == 0 && dy[i] == 1)
				{
					array[nx][ny] << 'U';
					if (array[x][y] != 1 && array[nx][ny] != array[x][y])
					{
						array[nx][ny] == 1;
					}
					difroot(nx, ny, grid, visited, n, m, (*array)[100]);
				}
				if (dx[i] == 0 && dy[i] == -1)
				{
					array[nx][ny] << 'D';
					if (array[x][y] != 1 && array[nx][ny] != array[x][y])
					{
						array[nx][ny] == 1;
					}
					difroot(nx, ny, grid, visited, n, m, (*array)[100]);
				}
			}
		}
	}
}