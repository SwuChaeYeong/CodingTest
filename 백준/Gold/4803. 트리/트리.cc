#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<bool> visited;

bool dfs(int u, int parent)
{
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            visited[v] = true;

            if (!dfs(v, u))
                return false;
        }
        else if (v != parent)
        {
            // 이미 방문된 정점인데 부모가 아니라면 사이클
            return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int caseNumber = 1;
    while (true)
    {
        cin >> N >> M;

        // 입력이 0 0인 경우 반복 종료
        if (N == 0 && M == 0)
            break;

        adj.assign(N + 1, {});
        visited.assign(N + 1, false);

        // 간선 입력
        for (int i = 0; i < M; i++)
        {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int treeCount = 0;
        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;

                // 연결 요소가 비어있어도(절단) DFS는 true 반환 > 트리로 계산
                if (dfs(i, -1))
                    treeCount++;
            }
        }

        if (treeCount == 0)
        {
            cout << "Case " << caseNumber << ": No trees.\n";
        }
        else if (treeCount == 1)
        {
            cout << "Case " << caseNumber << ": There is one tree.\n";
        }
        else
        {
            cout << "Case " << caseNumber << ": A forest of " << treeCount << " trees.\n";
        }
        caseNumber++;
    }

    return 0;
}