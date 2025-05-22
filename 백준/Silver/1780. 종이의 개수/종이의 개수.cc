#include <iostream>
#include <unordered_map>
using namespace std;

int a, b, c;
int paper[2187][2187];

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
        if (paper[x][y] == -1)
            a++;
        else if (paper[x][y] == 0)
            b++;
        else
            c++;
        return;
    }

    int newSize = size / 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Devide(x + i * newSize, y + j * newSize, newSize);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> paper[i][j];
        }
    }

    Devide(0, 0, n);

    cout << a << '\n' << b << '\n' << c;

    return 0;
}