#include <iostream>
#include <set>
#include <string>

using namespace std;

long long int Gcd(long long int a, long long int b)
{
    long long int remain = a % b;

    if (remain == 0)
        return b;
    else
        return Gcd(b, remain);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n1, n2;
    cin >> n1 >> n2;

    cout << (n1 * n2) / Gcd(n1, n2);

    return 0;
}