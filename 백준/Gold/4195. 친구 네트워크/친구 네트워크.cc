#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> parent, sz;
unordered_map<string, int> id;

int find(int x)
{
    // 부모가 본인인 경우
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

int unite(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        // b를  a에 붙임
        parent[b] = a;
        // 네트워크 크기 누적
        sz[a] += sz[b];
    }

    return sz[a];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int F;
        cin >> F;

        id.clear();
        parent.clear();
        sz.clear();

        int idx = 0;

        while (F--)
        {
            string a, b;
            cin >> a >> b;

            if (!id.count(a))
            {
                id[a] = idx++;
                parent.push_back(id[a]);
                sz.push_back(1);
            }

            if (!id.count(b))
            {
                id[b] = idx++;
                parent.push_back(id[b]);
                sz.push_back(1);
            }

            cout << unite(id[a], id[b]) << '\n';
        }
    }

    return 0;
}