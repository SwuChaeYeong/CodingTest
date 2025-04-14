#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;

    set<string> s;
    s.insert("ChongChong");

    string temp1, temp2;

    while (size--)
    {
        cin >> temp1 >> temp2;

        if (s.find(temp1) != s.end())
        {
            s.insert(temp2);
        }
        else if (s.find(temp2) != s.end())
        {
            s.insert(temp1);
        }
    }

    cout << s.size();

    return 0;
}