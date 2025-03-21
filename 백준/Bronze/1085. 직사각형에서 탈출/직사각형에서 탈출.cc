#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int minX, minY;

    if (y < h - y)
        minY = y;
    else
        minY = h - y;

    if (x < w - x)
        minX = x;
    else
        minX = w - x;

    minX < minY ? cout << minX : cout << minY;

    return 0;
}