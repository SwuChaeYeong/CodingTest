#include <iostream>
using namespace std;

int dp[101][10];
const int mod = 1000000000;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= 9; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j > 0) dp[i][j] += dp[i - 1][j - 1];
            if (j < 9) dp[i][j] += dp[i - 1][j + 1];

            dp[i][j] %= mod;
        }
    }

    int result = 0;
    for (int i = 0; i <= 9; i++)
    {
        result = (result + dp[n][i]) % mod;
    }

    cout << result;

    return 0;
}