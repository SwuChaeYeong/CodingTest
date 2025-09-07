#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
const int INF = 1e9;

vector<int> dijkstra(int start, int n, vector<vector<pair<int, int>>>& graph)
{
    // 전부 최대로 초기화
    // 시작점에서 i번 정점까지의 최단 거리
    vector<int> dist(n + 1, INF);
    // 거리, 노드 저장 -> 거리가 작은 것부터 꺼냄
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty())
    {
        // 큐에서 현재까지 거리, 정점을 꺼냄
        int curDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // 이미 더 짧은 거리로 방문한 적이 있다면 무시
        if (curDist > dist[u])
            continue;

        // u의 모든 인접 노드 (v, w) 확인
        // 더 짧은 경로를 발견하면 갱신하고 큐에 삽입
        for (auto edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;

            if (dist[v] > curDist + w)
            {
                dist[v] = curDist + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    // 테스트 케이스
    int T;
    cin >> T;

    while (T--)
    {
        int n, m, t;
        cin >> n >> m >> t;

        int s, g, h;
        cin >> s >> g >> h;

        vector<vector<pair<int, int>>> graph(n + 1);
        for (int i = 0; i < m; i++)
        {
            int a, b, d;
            cin >> a >> b >> d;
            graph[a].push_back({ b, d });
            graph[b].push_back({ a, d });
        }

        vector<int> candidates(t);
        for (int i = 0; i < t; i++)
        {
            cin >> candidates[i];
        }

        // 다익스트라 여러 번 실행
        // 1번에서 모든 노드
        auto distS = dijkstra(s, n, graph);
        // v1번에서 모든 노드
        auto distG = dijkstra(g, n, graph);
        // v2번에서 모든 노드
        auto distH = dijkstra(h, n, graph);

        vector<int> ans;
        for (int x : candidates)
        {
            int path1 = distS[g] + distG[h] + distH[x];
            int path2 = distS[h] + distH[g] + distG[x];

            if (distS[x] == min(path1, path2))
            {
                ans.push_back(x);
            }
        }

        sort(ans.begin(), ans.end());
        for (int x : ans)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}