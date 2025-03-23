#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n;
    cin >> n;

    long long int sum = 0;

    for (long long int i = 1; i <= n - 2; i++)
        sum += i * (i + 1) / 2;

    cout << sum << "\n" << 3;

    return 0;
}