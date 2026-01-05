#include <iostream>
using namespace std;

int parent[1000001];

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

    // 초기화
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }

    // 횟수만큼 연산
    while (m--)
    {
        int op, a, b;
        cin >> op >> a >> b;

        // 합집합 연산
        if (op == 0)
        {
            unite(a, b);
        }
        else
        {
            if (find(a) == find(b))
                cout << "YES\n";

            else
                cout << "NO\n";
        }
    }

    return 0;
}