#include <iostream>
#include <list>     // list
#include <queue>    // queue 
#include <algorithm>
using namespace std;

// BFS: https://olrlobt.tistory.com/41
// DFS: https://olrlobt.tistory.com/35

int row, col;
int nowSize = 0;
int maxSize = 0;
int cnt = 0;

void BFS(vector<vector<int>>& values, vector<vector<int>>& visited, int x, int y);
void DFS(vector<vector<int>>& values, vector<vector<int>>& visited);
void checkNeighbors(vector<vector<int>>& values, vector<vector<int>>& visited, int x, int y);

int main(){
    cin >> row >> col;

    // vector<vector<int>> 2차원 벡터 선언
    // (row, vector<int>(col,0)) 행 개수, 행을 vector로 초기화(col 만큼 0으로) 
    vector<vector<int>> values(row+2, vector<int>(col+2, 0));
    vector<vector<int>> visited(row+2, vector<int>(col+2, 0));

    // 입력받기
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            cin >> values[i][j];
        }
    }

    // BFS
    BFS(values, visited, row, cnt);

    // DFS
    // DFS(values, visited, row, cnt);

    // 출력하기
    cout << cnt << endl << maxSize;

    return 0;
}

void BFS(vector<vector<int>>& values, vector<vector<int>>& visited, int x, int y){
    queue<pair<int,int>> que;

    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            // 이미 방문한 노드거나 값이 0이면 continue
            if(visited[i][j] || values[i][j] == 0) continue; 
            
            // 노드 push, 방문 처리 
            visited[i][j] = 1; 
            que.push({i, j});

            // 큐가 빌때까지 확인 = 하나의 그림 확인
            while(!que.empty()){
                int x = que.front().first;
                int y = que.front().second;

                // 노드의 값이 1일 때는 인접 노드 큐에 push
                if(values[x][y] == 1){
                    nowSize++;
                    // 방문하지 않은 노드면 push
                    if(!visited[x-1][y]){ 
                        visited[x-1][y] = 1;
                        que.push({x-1, y});
                    }
                    if(!visited[x+1][y]){ 
                        visited[x+1][y] = 1;
                        que.push({x+1, y});
                    }
                    if(!visited[x][y-1]){ 
                        visited[x][y-1] = 1;
                        que.push({x, y-1});
                    }
                    if(!visited[x][y+1]){ 
                        visited[x][y+1] = 1;
                        que.push({x, y+1});
                    }
                }

                // 값이 0이든 1이든 pop은 하니까
                que.pop();
            }

            // nowSize와 maxSize 비교
            if(nowSize > maxSize) maxSize = nowSize;

            // nowSize 초기화
            nowSize = 0;
            cnt++;
        }
    }

}
void DFS(vector<vector<int>>& values, vector<vector<int>>& visited, int row, int col){
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            // 이미 방문한 노드거나 값이 0이면 continue
            if(visited[i][j] || values[i][j] == 0) continue; 
            visited[i][j] = 1; // 방문 처리

            // 값이 1이면 확인
            nowSize++;
            checkNeighbors(values, visited, i, j);

            // nowSize와 maxSize 비교
            if(nowSize > maxSize) maxSize = nowSize;

            // nowSize 초기화
            nowSize = 0;
            cnt++;
        }
    }
}
void checkNeighbors(vector<vector<int>>& values, vector<vector<int>>& visited, int x, int y){
    // 값이 1이니까 호출됨. 인접한 4개 확인 필요. 값이 1이고, 방문한적 없다면 재귀 시작
    if(values[x-1][y] && !visited[x-1][y]){
        visited[x-1][y] = 1; // 방문 체크하고
        nowSize++; // 크기 늘려주고
        checkNeighbors(values, visited, x-1, y); // 재귀
    }
    if(values[x+1][y] && !visited[x+1][y]){
        visited[x+1][y] = 1;
        nowSize++;
        checkNeighbors(values, visited, x+1, y);
    }
    if(values[x][y-1] && !visited[x][y-1]){
        visited[x][y-1] = 1;
        nowSize++;
        checkNeighbors(values, visited, x, y-1);
    }
    if(values[x][y+1] && !visited[x][y+1]){
        visited[x][y+1] = 1;
        nowSize++;
        checkNeighbors(values, visited, x, y+1);
    }
    return;
}



/*
1. values, visited (방문 확인용)
2. values[i][j] == 1일 때, 상하좌우 탐색
3. 인접한 1을 계속 찾아가며 nowSize++
    3-1. BFS는 Que에 넣어서 확인
    3-2. DFS는 재귀로 확인
5. 더 이상 갈 곳이 없으면 그림 하나 끝! 최대값 비교하고 갱신, 그림 개수+1
6. 다시 안 본 칸부터 시작 → 모든 좌표 다 탐색
7. 최종적으로 그림 개수, 최대 그림 넓이 출력
*/