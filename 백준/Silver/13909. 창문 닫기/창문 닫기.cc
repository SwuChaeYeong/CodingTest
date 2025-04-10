#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long size;
    cin >> size;

    int count = 0;

    for (long long i = 1; i * i <= size; i++)
    {
        count++;
    }

    cout << count;

    return 0;
}