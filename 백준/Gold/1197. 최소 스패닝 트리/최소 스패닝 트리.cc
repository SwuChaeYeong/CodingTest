#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

int parent[10001];

int findP (int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = findP(parent[x]);
}

bool unionP(int a, int b)
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

    int V, E;
    cin >> V >> E;

    // 입력
    vector<Edge> edges(E);
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // 부모 초기화
    for (int i = 1; i <= V; i++)
    {
        parent[i] = i;
    }

    //// 크루스칼
    // 가준치 기준 정렬
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
        });

    long long answer = 0;
    int count = 0;

    for (int i = 0; i < E; i++)
    {
        if (unionP(edges[i].u, edges[i].v))
        {
            answer += edges[i].w;
            count++;

            if (count == V - 1)
                break;
        }
    }

    cout << answer;

    return 0;
}