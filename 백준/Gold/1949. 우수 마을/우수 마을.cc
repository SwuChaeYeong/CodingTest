#include <iostream>
#include <vector>

using namespace std;

int N;
int people[10001];
vector<int> tree[10001];
bool visited[10001];
int dp[10001][2];

void dfs(int u)
{
    visited[u] = true;
    dp[u][0] = 0;
    dp[u][1] = people[u];

    for (int v : tree[u])
    {
        if (!visited[v])
        {
            dfs(v);

            // u가 우수 마을이 아닐 때
            dp[u][0] += max(dp[v][0], dp[v][1]);

            // u가 우수 마을일 때
            dp[u][1] += dp[v][0];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> people[i];

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1);

    cout << max(dp[1][0], dp[1][1]);

    return 0;
}