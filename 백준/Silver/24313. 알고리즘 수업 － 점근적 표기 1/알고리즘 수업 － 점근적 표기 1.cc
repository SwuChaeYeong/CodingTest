#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, n;

    cin >> a >> b >> c >> n;

    if (n * a + b <= c * n && a <= c)
        cout << 1;
    else
        cout << 0;

    return 0;
}