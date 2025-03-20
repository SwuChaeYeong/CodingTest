#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;

    int result;
    int count = 0;

    for (int i = 1; i <= x; i++)
    {
        if (x % i == 0)
        {
            count++;
            if (count == y)
            {
                cout << i;
                break;
            }
        }
    }

    if (count < y)
        cout << 0;

    return 0;
}