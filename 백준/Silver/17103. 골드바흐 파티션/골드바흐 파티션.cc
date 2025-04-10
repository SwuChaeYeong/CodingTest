#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int n = 1000000;
vector<bool> isPrime(n + 1, true);

void SetPrime()
{
    for (int i = 2; i * i <= n; i++)
    {
        if (!isPrime[i])
            continue;

        for (int j = i * i; j <= n; j += i)
            isPrime[j] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SetPrime();

    int size, num;

    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int count = 0;
        cin >> num;

        vector<int> v;

        for (int i = 2; i <= num; i++)
        {
            if (isPrime[i])
                v.push_back(i);
        }

        for (auto it = v.begin(); it != v.end(); it++)
        {
            int anotherNum = num - *it;

            if (binary_search(it, v.end(), anotherNum))
                count++;
        }

        cout << count << "\n";
    }

    return 0;
}