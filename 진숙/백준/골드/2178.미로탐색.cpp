#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
    cin >> N >> M;

    vector<pair<int, bool>> row(M); // 가로 한 줄
    vector<vector<pair<int, bool>>> maze(N, row); // N줄짜리 2차원 벡터 생성

    // 입력 받아서 2차원 벡터에 저장
    for(int i = 0; i < N; i++){
        string r;
        cin >> r;

        for(int j = j; j < M; j++){
            maze[i][j].first = r[j] - '0'; // 문자를 정수로
            maze[i][j].second = false; // 방문 여부 초기화
        }
    }

    // 확인
    int x = 0;
    int y = 0;

    int minCnt = N * M;
    int nowCnt = 0;

    while(true){
        // 마지막 지점에 도달했다면 멈추기 
        if(x == N-1 && y == M-1){
            nowCnt++;
            break;
        }
        // 값이 1인 경우 사방 확인
        if(maze[x][y].first == 1){  

        }
    }

    minCnt = (minCnt > nowCnt) ? nowCnt : minCnt;
    cout << minCnt;

    return 0;
}





/*
변수 선언
  - n, m: 미로의 행과 열 개수
  - r: 미로 한 줄 입력용 문자열
  - maze: 2차원 벡터 (n * m), 각 칸은 pair<int, bool>
      - first: 미로 값 (0 또는 1)
      - second: 방문 여부 (false로 초기화)
  - dq: 방문할 좌표를 저장하는 큐

입력
  1. n, m 입력 받기
  2. maze를 n행 m열로 초기화
  3. r 입력 받아서 문자 하나씩 나누어 maze[i][j].first 초기화
    - 반복문 돌리는김에 같이 second 는 false로 초기화

BFS 시작
  4. dq 시작점 (0,0) 삽입
  5. maze[0][0].second = true (방문 표시)
  6. 거리 배열 dist[n][m] 선언 및 0으로 초기화
  7. dist[0][0] = 1  // 시작점 거리 1로 설정

BFS 진행
  8. while dq 비어있지 않으면
       - (x, y) = dq 꺼내기
       - 만약 (x, y)가 도착점 (n-1, m-1) 이면
           - dist[x][y] 출력 후 종료

       - 현 위치 기준 4방향 확인
           - nx = x + dx[i]
           - ny = y + dy[i]

           - nx, ny가 미로 범위 밖이면 continue
           - maze[nx][ny].first가 0이면 continue
           - maze[nx][ny].second의 값이 true(이미 방문한 위치) continue

    - 작성중..

종료
  9. 도착점에 도달하면 dq 사이즈 출력
*/