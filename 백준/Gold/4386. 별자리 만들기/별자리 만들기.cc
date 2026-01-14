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

int parent[101];

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

    int N;
    cin >> N;

    vector<pair<double, double>> star(N);

    for (int i = 0; i < N; i++)
    {
        cin >> star[i].first >> star[i].second;
    }

    vector<Edge> edges;

    // 모든 별 쌍 간선 생성
    for (int i = 0; i < N; i++)
    {
        for (int j = 1 + i; j < N; j++)
        {
            double dx = star[i].first - star[j].first;
            double dy = star[i].second - star[j].second;
            double dist = sqrt(dx * dx + dy * dy);
            edges.push_back({ i, j, dist });
        }
    }

    // 부모 초기화
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
    }

    //// 크루스칼
    // 가준치 기준 정렬
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.cost < b.cost;
        });

    double result = 0.0;
    int cnt = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        if (unite(edges[i].u, edges[i].v))
        {
            result += edges[i].cost;
            cnt++;

            if (cnt == N - 1)
                break;
        }
    }

    printf("%.2f", result);

    return 0;
}