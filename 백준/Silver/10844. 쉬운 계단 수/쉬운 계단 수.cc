#include <iostream>
using namespace std;

const int mod = 1000000000;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n;
    cin >> n;

    int prev[10] = { 0 };
    int curr[10] = { 0 };

    for (int i = 1; i <= 9; i++)
    {
        prev[i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            curr[j] = 0;

            if (j > 0) curr[j] += prev[j - 1];
            if (j < 9) curr[j] += prev[j + 1];

            curr[j] %= mod;
        }

        for (int j = 0; j <= 9; j++)
        {
            prev[j] = curr[j];
        }
    }

    int result = 0;
    for (int i = 0; i <= 9; i++)
    {
        result = (result + prev[i]) % mod;
    }

    cout << result;

    return 0;
}