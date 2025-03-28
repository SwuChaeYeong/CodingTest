#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int size;
    cin >> size;

    int num, count[10001] = { 0, };

    for (int i = 0; i < size; i++)
    {
        cin >> num;
        count[num]++;
    }

    for (int i = 0; i <= 10000; i++)
    {
        if (count[i] != 0)
        {
            for (int j = 0; j < count[i]; j++)
            {
                cout << i << "\n";
            }
        }
    }

    return 0;
}