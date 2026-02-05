#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const int MAXN = 300000;
vector<pair<int, ll>> adj[MAXN + 1];
int subSize[MAXN + 1];
ll dp[MAXN + 1], ans[MAXN + 1];
int N;

void dfs1(int u, int p) {
    subSize[u] = 1;
    dp[u] = 0;
    for (auto& edge : adj[u]) {
        int v = edge.first;
        ll w = edge.second;
        if (v == p) continue;
        dfs1(v, u);
        subSize[u] += subSize[v];
        dp[u] += dp[v] + w * subSize[v];
    }
}

void dfs2(int u, int p) {
    for (auto& edge : adj[u]) {
        int v = edge.first;
        ll w = edge.second;
        if (v == p) continue;

        ans[v] = ans[u] + w * (N - 2LL * subSize[v]);
        dfs2(v, u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        adj[i].clear();
    }
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        adj[x].push_back({ y, w });
        adj[y].push_back({ x, w });
    }

    // 1번 노드를 루트로 1차 DFS
    dfs1(1, 0);

    // 루트 전체 거리합
    ans[1] = dp[1];

    // 2차 DFS
    dfs2(1, 0);

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}