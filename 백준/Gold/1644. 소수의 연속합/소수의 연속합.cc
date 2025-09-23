#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N;
    cin >> N;

    // 소수 배열 (에라토스테네스의 체)
    vector<bool> isPrime(N + 1, true);
    vector<int> primes;

    isPrime[0] = false;

    if (N >= 1)
        isPrime[1] = false;
    
    for (int i = 2; i * i <= N; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= N; i++)
    {
        if (isPrime[i])
            primes.push_back(i);
    }

    int start = 0, end = 0;
    int sum = 0, count = 0;

    while (true)
    {
        if (sum >= N)
        {
            if (sum == N)
                count++;

            sum -= primes[start++];
        }
        else
        {
            if (end == primes.size())
                break;

            sum += primes[end++];
        }
    }

    cout << count;

    return 0;
}