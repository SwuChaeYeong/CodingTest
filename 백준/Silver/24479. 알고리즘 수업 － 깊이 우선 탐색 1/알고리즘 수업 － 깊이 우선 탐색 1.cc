#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
int visited[100001];
int order = 1;

void dfs(int node)
{
    visited[node] = order++;

    for (int next : graph[node])
    {
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

    // 오름차순 정렬
    for (int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(R);

    // 결과
    for (int i = 1; i <= N; i++)
    {
        cout << visited[i] << '\n';
    }
      
    return 0;
}