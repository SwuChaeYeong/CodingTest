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

    int V, E;
    cin >> V >> E;

    // V x V 거리 행렬 초기화
    vector<vector<int>> dist(V + 1, vector<int>(V + 1, INF));

    // 간선 입력
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        // 같은 간선이 여러 번 들어올 수 있으므로 최소 비용만 반영
        dist[a][b] = min(dist[a][b], c);
    }

    // 플로이드 워셜 알고리즘
    for (int k = 1; k <= V; k++)            // 경유지
    {
        for (int i = 1; i <= V; i++)        // 출발지
        {
            for (int j = 1; j <= V; j++)    // 도착지
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // 자기 자신으로 돌아오는 최소 사이클 찾기
    int ans = INF;
    for (int i = 1; i <= V; i++)
    {
        ans = min(ans, dist[i][i]);
    }

    if (ans == INF)
        cout << -1;
    else
        cout << ans;

    return 0;
}