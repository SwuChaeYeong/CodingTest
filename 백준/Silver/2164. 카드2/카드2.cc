#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> q;

    int size;
    cin >> size;

    for (int i = 1; i <= size; i++)
    {
        q.push(i);
    }

    while (q.size() != 1)
    {
        q.pop();
        int temp = q.front();
        q.pop();
        q.push(temp);
    }

    cout << q.front();

    return 0;
}