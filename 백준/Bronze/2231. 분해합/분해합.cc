#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int num;
    cin >> num;

    for (int i = 1; i < num; i++)
    {
        int sum = i;
        int j = i;

        while (j)
        {
            sum += j % 10;
            j /= 10;
        }

        if (sum == num)
        {
            cout << i;
            return 0;
        }
    }

    cout << 0;

    return 0;
}