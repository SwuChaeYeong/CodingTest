#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int array[9][9];

    int max = 0, n = 0, m = 0;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> array[i][j];

            if (array[i][j] > max)
            {
                max = array[i][j];
                n = i;
                m = j;
            }
        }
    }

    cout << max << "\n" << n + 1 << " " << m + 1;

    return 0;
}