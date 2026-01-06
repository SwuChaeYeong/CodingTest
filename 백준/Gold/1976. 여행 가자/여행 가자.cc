#include <iostream>
using namespace std;

int parent[201];

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

    int N, M;
    cin >> N >> M;

    // 초기화
    for (int i = 0; i <= N; i++)
    {
        parent[i] = i;
    }

    // 연결
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int x;
            cin >> x;

            if (x == 1)
                unite(i, j);
        }
    }

    // 여행 계획 확인

    // 첫 번째 여행의 루트를 찾음
    int first;
    cin >> first;
    int root = find(first);

    // 두 번째부터 루트가 동일한지 확인
    for (int i = 1; i < M; i++)
    {
        int city;
        cin >> city;

        if (find(city) != root)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}