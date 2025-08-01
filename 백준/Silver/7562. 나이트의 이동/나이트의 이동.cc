#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int T, I;
int desX, desY;

const int MAX = 301;

// 각 정점 방문 순서 저장
bool visited[MAX][MAX];
// 각 정점에 도달했을 때 거리
int dist[MAX][MAX];

int nextPositionX[8] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int nextPositionY[8] = { 2, -2, 2, -2, 1, -1, 1, -1 };

void BFS(int x, int y)
{
    // 큐에 삽입 (방문 처리)
    queue<pair<int, int>> q;
    q.push({x, y});

    visited[y][x] = true;
    dist[y][x] = 0;

    // 큐가 빌 때까지
    while (!q.empty())
    {
        // 큐에서 꺼냄 (해당 노드에 도달)
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (cx == desX && cy == desY)
        {
            cout << dist[cy][cx] << '\n';
            return;
        }

        for (int dir = 0; dir < 8; dir++)
        {
            int nx = cx + nextPositionX[dir];
            int ny = cy + nextPositionY[dir];

            // 이동할 수 있는 경로고, 방문하지 않은 경우
            if (nx < I && nx >=0 && ny < I && ny >= 0)
            {
                if (!visited[ny][nx])
                {
                    // 방문 처리
                    visited[ny][nx] = true;
                    // 이전 경로에서 +1
                    dist[ny][nx] = dist[cy][cx] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    // 테스트 케이스
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        // 판 크기
        cin >> I;

        memset(dist, 0, sizeof(dist));
        memset(visited, false, sizeof(visited));

        int x, y;

        // 출발 위치
        cin >> x >> y;

        // 도착 위치
        cin >> desX >> desY;

        BFS(x, y);
    }
      
    return 0;
}