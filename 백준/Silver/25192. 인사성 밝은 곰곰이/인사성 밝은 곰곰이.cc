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
    string temp;

    int result = 0;

    while (size--)
    {
        cin >> temp;

        if (temp == "ENTER")
        {
            result += s.size();
            s.clear();
        }
        else
        {
            s.insert(temp);
        }
    }

    result += s.size();
    cout << result;

    return 0;
}