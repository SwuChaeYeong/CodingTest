#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N;

// 맵 입력
vector<string> map;

// 각 정점 방문 순서 저장
bool visited[100][100];
// 각 정점에 도달했을 때 거리
int dist[100][100];

// 상하좌우 방향
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void BFS(int x, int y)
{
    // 큐에 삽입 (방문 처리)
    queue<pair<int, int>> q;
    q.push({ x, y });

    visited[x][y] = true;
    dist[x][y] = 1;

    // 큐가 빌 때까지
    while (!q.empty())
    {
        // 큐에서 꺼냄 (해당 노드에 도달)
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (cx == N - 1 && cy == M - 1)
        {
            cout << dist[cx][cy];
            return;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            // 맵 범위를 벗어나지 않는지 체크
            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                // 이동할 수 있는 경로고, 방문하지 않은 경우
                if (map[nx][ny] == '1' && !visited[nx][ny])
                {
                    // 방문 처리
                    visited[nx][ny] = true;
                    // 이전 경로에서 +1
                    dist[nx][ny] = dist[cx][cy] + 1;
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

    // 차례로 row, col
    cin >> N >> M;
    map.resize(N);

    // 미로 입력
    for (int i = 0; i < N; i++)
    {
        cin >> map[i];
    }

    // BFS (최단거리)
    BFS(0, 0);
      
    return 0;
}