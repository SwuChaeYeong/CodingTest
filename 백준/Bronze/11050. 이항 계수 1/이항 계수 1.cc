#include <iostream>
#include <math.h>
using namespace std;

int factorial(int n)
{
    int result = 1;

    for (int i = n; i > 0; i--)
    {
        result *= i;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int ans = factorial(n) / (factorial(k) * factorial(n - k));
    cout << ans;

    return 0;
}