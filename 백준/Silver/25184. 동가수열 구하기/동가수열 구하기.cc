#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N;
    cin >> N;

    int half = N / 2;

    for (int i = 1; i <= half; i++)
    {
        cout << i + half << ' ' << i << ' ';
    }

    if (N % 2 == 1)
    {
        cout << N;
    }

    return 0;
}