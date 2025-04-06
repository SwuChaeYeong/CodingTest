#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, string, greater<>> member;

    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        string name, con;
        cin >> name >> con;

        member[name] = con;
    }

    map<string, string>::iterator it;
    for (it = member.begin(); it != member.end(); it++)
    {
        if (it->second == "enter")
        {
            cout << it->first << "\n";
        }
    }

    return 0;
}