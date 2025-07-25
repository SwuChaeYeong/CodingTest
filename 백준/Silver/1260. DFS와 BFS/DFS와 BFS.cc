#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 각 정점 인접 리스트
vector<int> graph[10001];
// 각 정점 방문 순서 저장
bool visited[10001];

void DFS(int node)
{
    visited[node] = true;
    cout << node << " ";

    for (int next : graph[node])
    {
        if (!visited[next])
        {
            DFS(next);
        }
    }
}

void BFS(int node)
{
    queue<int> q;
    q.push(node);

    // 방문 처리
    visited[node] = true;

    // 출력
    cout << node << " ";

    // 큐가 빌 때까지
    while (!q.empty())
    {
        // 현재 노드
        int cur = q.front();
        q.pop();

        for (int next : graph[cur])
        {
            // 방문하지 않은 노드면
            if (!visited[next])
            {
                // 방문 처리
                visited[next] = true;
                q.push(next);
                
                // 출력
                cout << next << " ";
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N, M, V;
    cin >> N >> M >> V;

    // 간선 입력
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 정점 정렬
    for (int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    // 깊이 우선 탐색
    DFS(V);
    cout << '\n';

    // visited 배열 초기화
    fill(visited, visited + 10001, false);

    // 너비 우선 탐색
    BFS(V);
      
    return 0;
}