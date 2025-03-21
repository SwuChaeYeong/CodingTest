#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x[3];
    int y[3];

    for (int i = 0; i < 3; i++)
    {
        cin >> x[i] >> y[i];
    }

    sort(x, x + 3);
    sort(y, y + 3);

    if (x[0] == x[1])
        cout << x[2] << " ";
    else
        cout << x[0] << " ";

    if (y[0] == y[1])
        cout << y[2];
    else
        cout << y[0];

    return 0;
}