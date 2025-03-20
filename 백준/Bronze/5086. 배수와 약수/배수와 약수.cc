#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;

    while (true)
    {
        cin >> x >> y;

        if (x == 0 && y == 0)
            break;

        if (x % y == 0)
            cout << "multiple\n";
        else if (y % x == 0)
            cout << "factor\n";
        else
            cout << "neither\n";
    }

    return 0;
}