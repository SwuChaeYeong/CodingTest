#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int weight[10001];
vector<int> tree[10001];
int dp[10001][2];
bool visited[10001];
vector<int> result;

void dfs(int u, int parent)
{
    visited[u] = true;
    dp[u][0] = 0;
    dp[u][1] = weight[u];

    for (int v : tree[u])
    {
        if (v == parent)
            continue;


        dfs(v, u);

        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

// 노드 추적
void trace(int u, int parent, bool parentSelected)
{
    bool selectU = false;

    if (!parentSelected && dp[u][1] > dp[u][0])
    {
        selectU = true;
        result.push_back(u);
    }

    for (int v : tree[u])
    {
        if (v == parent) continue;

        trace(v, u, selectU);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> weight[i];
    }

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0);

    cout << max(dp[1][0], dp[1][1]) << '\n';
    trace(1, 0, false);

    sort(result.begin(), result.end());

    for (int x : result)
        cout << x << " ";

    return 0;
}