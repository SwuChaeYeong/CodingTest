#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    set<string> s;

    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i; j < str.length(); j++)
        {
            s.insert(str.substr(i, j - i + 1));
        }
    }

    cout << s.size();

    return 0;
}