#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i <= sqrt(n); i++) 
    {
        if (n % i == 0)
            return false;
    }

    //소수
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while (true)
    {
        cin >> n;
        if (n == 0)
            break;

        int result = 0;

        for (int i = n + 1; i <= 2 * n; i++)
        {
            if (isPrime(i))
                result++;
        }

        cout << result << "\n";
    }

    return 0;
}