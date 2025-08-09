#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    int x, y, broken;
};

int N, M;
vector<string> map;

// 행, 열, 벽부숨 여부
bool visited[1000][1000][2];
int dist[1000][1000][2];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0,0,-1,1 };


int BFS()
{
    queue<Node> q;
    q.push({ 0, 0, 0 });
    visited[0][0][0] = true;
    dist[0][0][0] = 1;

    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();

        int x = cur.x;
        int y = cur.y;
        int broken = cur.broken;

        // 도착 지점이면
        if (x == N - 1 && y == M - 1)
            return dist[x][y][broken];

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // 맵 이탈 검사
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;

            // 벽이 아닌 경우
            if (map[nx][ny] == '0' && !visited[nx][ny][broken])
            {
                visited[nx][ny][broken] = true;
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
                q.push({ nx, ny, broken });
            }
            // 벽인데 아직 안 부숨
            else if (map[nx][ny] == '1' && broken == 0 && !visited[nx][ny][1])
            {
                visited[nx][ny][1] = true;
                dist[nx][ny][1] = dist[x][y][broken] + 1;
                q.push({ nx, ny, 1 });
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    cin >> N >> M;
    map.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> map[i];
    }

    cout << BFS();
      
    return 0;
}