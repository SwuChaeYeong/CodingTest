#include <iostream>
#include <algorithm>

using namespace std;

struct Coordinate
{
    int x;
    int y;
};

bool compare(Coordinate a, Coordinate b)
{
    if (a.y == b.y)
        return a.x < b.x;
    else
        return a.y < b.y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;

    Coordinate arr[100001];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i].x >> arr[i].y;
    }

    sort(arr, arr + size, compare);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i].x << " " << arr[i].y << "\n";
    }

    return 0;
}