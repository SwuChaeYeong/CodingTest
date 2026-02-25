#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N;
    cin >> N;

    cout << 2000 << "\n";

    // 1을 1000개
    for (int i = 0; i < 1000; ++i)
        cout << 1 << " ";

    // 1000을 1000개
    for (int i = 0; i < 1000; ++i)
        cout << 1000 << " ";

    return 0;
}