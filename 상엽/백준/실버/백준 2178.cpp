#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

void BFS(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited, int n, int m)
{
    visited[x][y] = true;

    int i;
    for (i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
            if (grid[nx][ny] == 1 && !visited[nx][ny])
            {
                grid[nx][ny] = grid[x][y] + 1;
                BFS(nx, ny, grid, visited, n, m);
            }
        }

    }
}

int main()
{
    int n, m, i, j;

    cin >> n >> m;

    vector<vector<int>>grid(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    grid[0][0] = 1;

    BFS(0, 0, grid, visited, n, m);

    cout << grid[n - 1][m - 1] << endl;

    return 0;
}
