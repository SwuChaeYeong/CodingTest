#include <iostream>
#include <cmath>

using namespace std;

void hanoi(int n, int from, int by, int to)
{
    if (n == 1)
    {
        cout << from << " " << to << "\n";
    }
    else
    {
        hanoi(n - 1, from, to, by);
        cout << from << " " << to << "\n";
        hanoi(n - 1, by, from, to);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n;
    cin >> n;

    cout << int(pow(2, n)) - 1 << "\n";
    hanoi(n, 1, 2, 3);

    return 0;
}