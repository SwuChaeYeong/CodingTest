#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

const int MAX = 100;

int tomato[MAX][MAX][MAX];
int day[MAX][MAX][MAX];

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int M, N, H;
    cin >> M >> N >> H;

    queue<tuple<int, int, int>> q;

    for (int h = 0; h < H; h++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                cin >> tomato[h][n][m];

                // 익은 것들 전부 큐에 삽입
                if (tomato[h][n][m] == 1)
                {
                    q.push({ h, n, m });
                }
            }
        }
    }

    // 큐가 빌 때까지
    while (!q.empty())
    {
        // 큐에서 꺼냄 (해당 노드에 도달)
        tuple<int, int, int> cur = q.front();
        q.pop();

        int z = get<0>(cur);
        int y = get<1>(cur);
        int x = get<2>(cur);

        for (int dir = 0; dir < 6; dir++)
        {
            int nz = z + dz[dir];
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            // 이동할 수 있는 경로고, 방문하지 않은 경우
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && nz >= 0 && nz < H)
            {   
                // 토마토가 익지 않았으면
                if (tomato[nz][ny][nx] == 0)
                {
                    // 토마토 익음
                    tomato[nz][ny][nx] = 1;
                    // 이전 경로에서 +1
                    day[nz][ny][nx] = day[z][y][x] + 1;
                    // 익었으니까 큐에 삽입
                    q.push({ nz, ny, nx });
                }
            }
        }
    }

    int result = 0;

    // 연산 다 끝나고 나면
    for (int h = 0; h < H; h++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                // 안 익은 게 있으면
                if (tomato[h][n][m] == 0) {
                    cout << -1;
                    return 0;
                }
                result = max(result, day[h][n][m]);
            }
        }
    }

    cout << result;
      
    return 0;
}