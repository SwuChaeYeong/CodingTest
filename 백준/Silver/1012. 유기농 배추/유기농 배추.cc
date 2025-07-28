#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int M, N;
// 맵 입력
short map[50][50];

// 각 정점 방문 순서 저장
bool visited[50][50];
int houseCount = 0;

// 상하좌우 방향
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void BFS(int x, int y)
{
    // 방문 처리
    visited[x][y] = true;

    // 큐 (x, y 저장해야 하므로 pair 사용)
    queue<pair<int, int>> q;
    q.push({ x, y });


    while (!q.empty())
    {
        // 큐에서 pop
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        // 현재 꺼낸 노드 상하좌우 탐색
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            // 맵 범위를 벗어나지 않는지 체크
            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                // 집이 있고, 방문하지 않은 경우
                if (map[nx][ny] == 1 && !visited[nx][ny])
                {
                    // 방문 처리
                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int T, K;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> M >> N >> K;


        // 초기화
        memset(visited, false, sizeof(visited));
        memset(map, 0, sizeof(map));
        houseCount = 0;

        for (int i = 0; i < K; i++)
        {
            int x, y;
            cin >> x >> y;

            map[y][x] = 1;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                // 배추가 있고 방문하지 않은 경우
                if (map[i][j] == 1 && !visited[i][j])
                {
                    houseCount++;
                    BFS(i, j);
                }
            }
        }

        cout << houseCount << '\n';
    }
      
    return 0;
}