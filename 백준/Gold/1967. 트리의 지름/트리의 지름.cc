#include <iostream>
#include <vector>
#include <tuple>
#include <stack>
using namespace std;

// start에서 가장 먼 정점과 그 거리 반환
pair<int, long long> farthest(int start, const vector<vector<pair<int, int>>>& adj)
{
    // node, parent, dist
    stack<tuple<int, int, long long>> st;
    st.emplace(start, -1, 0);
    int farNode = start;
    long long farDist = 0;

    while (!st.empty())
    {
        int u = get<0>(st.top());
        int p = get<1>(st.top());
        long long d = get<2>(st.top());

        st.pop();

        if (d > farDist)
        {
            farDist = d;
            farNode = u;
        }

        for (const auto& e : adj[u])
        {
            int v = e.first;
            int w = e.second;

            if (v == p)
                continue;

            st.emplace(v, u, d + (long long)w);
        }
    }

    return { farNode, farDist };
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N;
    cin >> N;

    vector<vector<pair<int, int>>> adj(N + 1);

    for (int i = 0; i < N - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    auto p1 = farthest(1, adj);
    auto p2 = farthest(p1.first, adj);

    cout << p2.second;

    return 0;
}