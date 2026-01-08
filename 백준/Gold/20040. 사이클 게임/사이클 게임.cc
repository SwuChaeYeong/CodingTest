#include <iostream>
using namespace std;

int parent[500001];

int find(int x)
{
    // 부모가 본인인 경우
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
        parent[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;

        // 이미 같은 집합 > 사이클 발생
        if (find(a) == find(b))
        {
            cout << i;
            return 0;
        }

        unite(a, b);
    }

    // 사이클이 끝까지 안 생긴 경우
    cout << 0;

    return 0;
}