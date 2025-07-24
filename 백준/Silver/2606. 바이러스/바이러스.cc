#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 각 정점 인접 리스트
vector<int> graph[100001];
// 각 정점 방문 순서 저장
bool visited[100001];
int cnt = 0;

void dfs(int node)
{
    // 현재 노드 방문 -> 방문 순서 변경
    visited[node] = true;
    cnt++;

    // cur 인접 정점 순회
    for (int next : graph[node])
    {
        // 아직 방문 안 했으면
        if (visited[next] == false)
            dfs(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N, M;
    cin >> N >> M;

    // 간선 입력
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);

    // 결과
    cout << cnt - 1;
      
    return 0;
}