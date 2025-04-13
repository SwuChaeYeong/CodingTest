#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int result = 1;

    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }

    cout << result;

    return 0;
}