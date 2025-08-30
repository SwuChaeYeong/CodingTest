#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int N, E;
// 정점 u에서 나가는 간선 목록({v, w}) v
vector<vector<pair<int, int>>> graph;

vector<int> dijkstra(int start)
{
    // 전부 최대로 초기화
    // 시작점에서 i번 정점까지의 최단 거리
    vector<int> dist(N + 1, INF);
    // 거리, 노드 저장 -> 거리가 작은 것부터 꺼냄
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater< >> pq;

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
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    // 정점 개수, 간선 개수
    cin >> N >> E;
    graph.resize(N + 1);

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    // 경유해야 하는 정점
    int v1, v2;
    cin >> v1 >> v2;

    // 다익스트라 여러 번 실행
    // 1번에서 모든 노드
    auto dist1 = dijkstra(1);
    // v1번에서 모든 노드
    auto distV1 = dijkstra(v1);
    // v2번에서 모든 노드
    auto distV2 = dijkstra(v2);

    // 1 -> v1 -> v2 -> N
    long long path1 = (long long)dist1[v1] + distV1[v2] + distV2[N];
    // 1 -> v2 -> v1 -> N
    long long path2 = (long long)dist1[v2] + distV2[v1] + distV1[N];

    long long ans = min(path1, path2);

    if (ans >= INF)
        cout << -1 << "\n";

    else
        cout << ans << "\n";

    return 0;
}