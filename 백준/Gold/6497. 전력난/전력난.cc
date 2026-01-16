#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, cost;
};

int parent[200001];

int findP (int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = findP(parent[x]);
}

bool unite(int a, int b)
{
    a = findP(a);
    b = findP(b);

    // 같은 집합
    if (a == b)
        return false;

    parent[b] = a;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    while (true)
    {
        int m, n;
        cin >> m >> n;

        // 종료
        if (m == 0 && n == 0)
            break;

        // 간선 생성
        vector<Edge> edges;
        long long totalCost = 0;

        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            edges.push_back({ x, y, z });
            totalCost += z;
        }

        // 유니온 파인드 초기화
        for (int i = 0; i < m; i++)
        {
            parent[i] = i;
        }

        //// 크루스칼
        // 정렬
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.cost < b.cost;
            });

        // MST 비용
        long long mstCost = 0;

        for (int i = 0; i < edges.size(); i++)
        {
            if (unite(edges[i].u, edges[i].v))
            {
                mstCost += edges[i].cost;
            }
        }

        cout << totalCost - mstCost << '\n';
    }

    return 0;
}