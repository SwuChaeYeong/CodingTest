#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, int> people;
    int n, m;
    vector<string> result;

    cin >> n >> m;

    for (int i = 0; i < n + m; i++)
    {
        string str;
        cin >> str;

        people[str]++;

        if (people[str] > 1)
            result.push_back(str);
    }

    sort(result.begin(), result.end());
    cout << result.size() << "\n";

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\n";
    }

    return 0;
}