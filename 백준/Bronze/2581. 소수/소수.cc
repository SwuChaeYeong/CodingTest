#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int start, end;
    cin >> start >> end;

    int min = 100001;
    int sum = 0;

    if (start == 1)
        start++;

    for (int i = start; i <= end; i++)
    {
        bool isPrime = true;

        if (i % 2 == 0 && i != 2)
            continue;

        for (int j = 3; j < i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            if (i < min)
                min = i;
            
            sum += i;
        }
    }

    if (min == 100001 && sum == 0)
        cout << -1;
    else
        cout << sum << "\n" << min;

    return 0;
}