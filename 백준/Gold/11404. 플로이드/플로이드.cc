#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INF = 1e9;

// u -> v, 가중치 w
struct Edge
{
    int u, v;
    int w;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n, m;
    cin >> n >> m;

    // n x n 거리 행렬 초기화
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    // 자기 자신으로 가는 비용은 0
    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }

    // 간선 입력
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        // 같은 간선이 여러 번 들어올 수 있으므로 최소 비용만 반영
        dist[a][b] = min(dist[a][b], c);
    }

    // 플로이드 워셜 알고리즘
    for (int k = 1; k <= n; k++)            // 경유지
    {
        for (int i = 1; i <= n; i++)        // 출발지
        {
            for (int j = 1; j <= n; j++)    // 도착지
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // 출력
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
                cout << 0 << " ";

            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}