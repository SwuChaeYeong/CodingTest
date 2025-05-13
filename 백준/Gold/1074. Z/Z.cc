#include <iostream>
using namespace std;

int n, r, c;
int number = 0;

void Devide(int x, int y, int n)
{
    if (n == 0)
        return;

    int size = 1 << (n - 1);
    int count = size * size;

    if (r < x + size && c < y + size)
    {
        Devide(x, y, n-1);
    }
    else if (r < x + size && c >= y + size)
    {
        number += count * 1;
        Devide(x, y + size, n - 1);
    }
    else if (r >= x + size && c < y + size)
    {
        number += count * 2;
        Devide(x + size, y, n - 1);
    }
    else
    {
        number += count * 3;
        Devide(x + size, y + size, n - 1);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    cin >> n >> r >> c;
    Devide(0, 0, n);

    cout << number;

    return 0;
}