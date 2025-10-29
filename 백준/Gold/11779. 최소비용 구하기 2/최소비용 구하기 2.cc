#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <stack>

using namespace std;
const int INF = numeric_limits<int>::max();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N, M;
    cin >> N >> M;

    // 그래프
    vector <vector<pair<int, int>>> graph(N + 1);
    // 그래프 입력
    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
    }

    int start, end;
    cin >> start >> end;

    vector<int> dist(N + 1, INF);
    vector<int> prev(N + 1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty())
    {
        pair<int, int> top = pq.top();
        int cost = top.first;
        int cur = top.second;

        pq.pop();

        if (cost > dist[cur])
            continue;

        for (pair<int, int> edge : graph[cur])
        {
            int next = edge.first;
            int weight = edge.second;

            if (dist[next] > cost + weight)
            {
                dist[next] = cost + weight;
                prev[next] = cur;
                pq.push({ dist[next], next });
            }
        }
    }

    // 경로 복원
    stack<int> path;
    int cur = end;
    while (cur != -1)
    {
        path.push(cur);
        cur = prev[cur];
    }

    cout << dist[end] << '\n';
    cout << path.size() << '\n';
    while (!path.empty())
    {
        cout << path.top() << '\n';
        path.pop();
    }

    return 0;
}