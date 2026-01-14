#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Edge {
    int u, v;
    double cost;
};

int parent[1001];

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

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pos(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> pos[i].first >> pos[i].second;

        // 부모 초기화
        parent[i] = i;
    }

    // 이미 연결된 통로
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }


    // 모든 간선 생성
    vector<Edge> edges;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1 + i; j <= N; j++)
        {
            double dx = pos[i].first - pos[j].first;
            double dy = pos[i].second - pos[j].second;
            double dist = sqrt(dx * dx + dy * dy);
            edges.push_back({ i, j, dist });
        }
    }

    //// 크루스칼
    // 가준치 기준 정렬
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.cost < b.cost;
        });

    double answer = 0.0;

    for (int i = 0; i < edges.size(); i++)
    {
        if (unite(edges[i].u, edges[i].v))
        {
            answer += edges[i].cost;
        }
    }

    printf("%.2f", answer);

    return 0;
}