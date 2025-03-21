#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    int minX = 100000, maxX = -100000;
    int minY = 100000, maxY = -100000;

    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int x, y;
        cin >> x >> y;

        if (x < minX)
            minX = x;
        if (x > maxX)
            maxX = x;

        if (y < minY)
            minY = y;
        if (y > maxY)
            maxY = y;
    }

    cout << (maxX - minX) * (maxY - minY);
}