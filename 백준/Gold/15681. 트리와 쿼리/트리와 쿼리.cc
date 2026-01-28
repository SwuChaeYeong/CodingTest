#include <iostream>
#include <vector>

using namespace std;

int N, R, Q;
vector<int> tree[100001];
int dp[100001];
bool visited[100001];

int dfs(int u)
{
    visited[u] = true;
    dp[u] = 1;

    for (int v : tree[u])
    {
        if (!visited[v])
        {
            dp[u] += dfs(v);
        }
    }
    return dp[u];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    cin >> N >> R >> Q;

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(R);

    while (Q--)
    {
        int u;
        cin >> u;
        cout << dp[u] << '\n';
    }

    return 0;
}