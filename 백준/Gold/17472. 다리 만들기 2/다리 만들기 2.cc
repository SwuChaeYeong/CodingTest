#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge
{
    int a, b, cost;
};

int N, M;
int land[10][10];
int parent[7];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

vector<Edge> edges;

// 유니온 파인드
int findP(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = findP(parent[x]);
}

void unite(int a, int b)
{
    a = findP(a);
    b = findP(b);

    // 같은 집합
    if (a != b)
        parent[b] = a;
}

// 섬 번호 매기기
void bfs(int sx, int sy, int idx)
{
    queue<pair<int, int>> q;
    q.push({ sx, sy });
    land[sx][sy] = idx;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;

            if (land[nx][ny] == 1)
            {
                land[nx][ny] = idx;
                q.push({ nx, ny });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    // 입력
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> land[i][j];

    // 섬 번호
    int islandCnt = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (land[i][j] == 1)
            {
                bfs(i, j, ++islandCnt);
            }
        }
    }

    // 다리 후보 탐색
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            if (land[x][y] >= 2)
            {
                int from = land[x][y];

                for (int d = 0; d < 4; d++)
                {
                    int nx = x;
                    int ny = y;
                    int len = 0;

                    while (true)
                    {
                        nx += dx[d];
                        ny += dy[d];

                        if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                            break;

                        if (land[nx][ny] == 0)
                        {
                            len++;
                        }
                        else
                        {
                            if (land[nx][ny] != from && len >= 2)
                            {
                                edges.push_back({ from, land[nx][ny], len });
                            }
                            break;
                        }
                    }
                }
            }
        }
    }

    // 크루스칼
    for (int i = 2; i <= islandCnt; i++)
        parent[i] = i;

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.cost < b.cost;
        });

    int result = 0;
    int connect = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        int a = edges[i].a;
        int b = edges[i].b;
        int cost = edges[i].cost;

        if (findP(a) != findP(b))
        {
            unite(a, b);
            result += cost;
            connect++;
        }
    }

    if (connect == islandCnt - 2)
        cout << result;
    else
        cout << -1;

    return 0;
}