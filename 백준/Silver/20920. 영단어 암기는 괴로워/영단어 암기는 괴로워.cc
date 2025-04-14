#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<string, int> mp;

bool Compare(string a, string b)
{
    if (a.size() == b.size() && mp[a] == mp[b])
    {
        return a < b;
    }
    else if (mp[a] == mp[b])
    {
        return a.size() > b.size();
    }
    return mp[a] > mp[b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> word;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        if (str.size() < m)
            continue;

        if (mp.find(str) == mp.end())
        {
            word.push_back(str);
        }
        
        mp[str]++;
    }

    sort(word.begin(), word.end(), Compare);

    for (int i = 0; i < word.size(); i++)
    {
        cout << word[i] << "\n";
    }

    return 0;
}