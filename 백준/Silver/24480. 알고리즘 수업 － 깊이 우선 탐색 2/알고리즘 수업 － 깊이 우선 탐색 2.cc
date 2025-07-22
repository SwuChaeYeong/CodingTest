#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 각 정점 인접 리스트
vector<int> graph[100001];
// 각 정점 방문 순서 저장
int visited[100001];
int order = 1;

void dfs(int node)
{
    // 현재 노드 방문 -> 방문 순서 변경
    visited[node] = order++;

    // 인접 노드 순회
    for (int next : graph[node])
    {
        // 아직 방문 안 했으면
        if (visited[next] == 0)
            dfs(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N, M, R;
    cin >> N >> M >> R;

    // 간선 입력
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 내림차순 정렬
    for (int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end(), greater<>());
    }

    dfs(R);

    // 결과
    for (int i = 1; i <= N; i++)
    {
        cout << visited[i] << '\n';
    }
      
    return 0;
}