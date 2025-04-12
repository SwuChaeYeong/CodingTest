#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> q;

    int size, num;
    cin >> size >> num;

    for (int i = 1; i <= size; i++)
    {
        q.push(i);
    }

    cout << "<";

    while (!q.empty())
    {
        for (int i = 1; i < num; i++)
        {
            q.push(q.front());
            q.pop();
        }

        cout << q.front();

        if (q.size() >= 2)
            cout << ", ";

        q.pop();
    }

    cout << ">";

    return 0;
}