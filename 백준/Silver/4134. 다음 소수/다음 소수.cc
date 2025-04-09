#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long long n)
{
    if (n <= 1)
        return false;

    if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (long long i = 5; i <= sqrt(n); i++) 
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

    long long size;
    cin >> size;

    long long num;
    
    for (long long i = 0; i < size; i++)
    {
        cin >> num;

        for (long long j = num;; j++)
        {
            if (isPrime(j))
            {
                cout << j << "\n";
                break;
            }
        }
    }

    return 0;
}