#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> tree[1000001];
bool visited[1000001];
int dp[1000001][2];

void dfs(int u)
{
    visited[u] = true;
    dp[u][0] = 0;   // u가 얼리 어답터 아님
    dp[u][1] = 1;   // u가 얼리 어답터임

    for (int v : tree[u])
    {
        if (!visited[v])
        {
            dfs(v);

            // u가 얼리 어답터가 아닐 때
            dp[u][0] += dp[v][1];

            // u가 얼리 어답터일 때
            dp[u][1] += min(dp[v][0], dp[v][1]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1);

    cout << min(dp[1][0], dp[1][1]);

    return 0;
}