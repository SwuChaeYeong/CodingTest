#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    for (int i = 0; i < test; i++)
    {
        long long result = 1;
        int n;
        int m;

        cin >> n >> m;

        int d = 1;
        for (int j = m; j > m - n; j--)
        {
            result *= j;
            result /= d;

            d++;
        }

        cout << result << "\n";
    }


    return 0;
}