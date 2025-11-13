#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parent(N + 1, 0);
    queue<int> q;
    q.push(1);

    // 루트 표시
    parent[1] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (parent[v] == 0)
            {
                parent[v] = u;
                q.push(v);
            }
        }
    }

    for (int i = 2; i <= N; i++)
    {
        cout << parent[i] << '\n';
    }

    return 0;
}