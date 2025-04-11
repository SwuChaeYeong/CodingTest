#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> line;
    int size, now = 1;

    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int input;
        cin >> input;

        if (input == now)
            now++;
        else
            line.push(input);

        while (!line.empty() && line.top() == now)
        {
            line.pop();
            now++;
        }
    }

    if (line.empty())
        cout << "Nice";
    else
        cout << "Sad";

    return 0;
}