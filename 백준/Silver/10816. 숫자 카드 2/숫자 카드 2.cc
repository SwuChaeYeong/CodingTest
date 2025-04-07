#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    map<int, int> list;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        list[temp]++;
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;

        cout << list[temp] << " ";
    }

    return 0;
}