#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
            cout << " ";

        for (int k = 0; k < 2 * i + 1; k++)
            cout << "*";

        cout << "\n";
    }
    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < size - i; j++)
            cout << " ";

        for (int k = 0; k < i * 2 - 1; k++)
            cout << "*";

        cout << "\n";
    }

    return 0;
}