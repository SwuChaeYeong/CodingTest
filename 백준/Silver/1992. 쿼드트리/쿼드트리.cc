#include <iostream>
#include <unordered_map>
using namespace std;

int paper[64][64];

bool IsSame(int x, int y, int size)
{
    int color = paper[x][y];

    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (paper[i][j] != color)
                return false;
        }
    }
    return true;
}

void Devide(int x, int y, int size)
{
    if (IsSame(x, y, size))
    {
        cout << paper[x][y];
        return;
    }

    cout << '(';
    int newSize = size / 2;

    Devide(x, y, newSize);
    Devide(x, y + newSize, newSize);
    Devide(x + newSize, y, newSize);
    Devide(x + newSize, y + newSize, newSize);

    cout << ')';
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;

        for (int j = 0; j < n; j++)
        {
            paper[i][j] = line[j] - '0';
        }
    }

    Devide(0, 0, n);

    return 0;
}