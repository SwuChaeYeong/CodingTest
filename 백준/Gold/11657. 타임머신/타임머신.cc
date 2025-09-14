#include <iostream>
#include <vector>
#include <limits>

using namespace std;
const long long INF = 1e18;

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

    // 정점, 간선 개수
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // 거리 테이블
    vector<long long> dist(V + 1, INF);
    // 처음(시작) 거리 0 (출발지 1번)
    dist[1] = 0;

    // V-1번 반복
    for (int i = 1; i < V; i++)
    {
        bool updated = false;

        for (const auto& e : edges)
        {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v])
            {
                dist[e.v] = dist[e.u] + e.w;
                updated = true;
            }
        }

        // 더 갱신 없으면 일찍 종료 가능
        if (!updated)
            break;
    }

    // 음수 사이클 여부 검사
    for (const auto& e : edges)
    {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v])
        {
            cout << -1 << '\n';
            return 0;
        }
    }

    // 출력
    for (int i = 2; i <= V; i++)
    {
        if (dist[i] == INF)
            cout << -1 << '\n';

        else
            cout << dist[i] << '\n';
    }

    return 0;
}