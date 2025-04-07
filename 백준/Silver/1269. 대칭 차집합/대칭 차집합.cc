#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, count = 0;
    map<int, int> set1;
    map<int, int> set2;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        set1[temp]++;
    }

    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;

        set2[temp]++;
    }

    for (auto it = set1.begin(); it != set1.end(); it++)
    {
        if (set2[it->first] == 0)
            count++;
    }

    for (auto it = set2.begin(); it != set2.end(); it++)
    {
        if (set1[it->first] == 0)
            count++;
    }

    cout << count;

    return 0;
}