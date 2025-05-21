#include <iostream>
#include <vector>
using namespace std;

long dp[101];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int size;
    cin >> size;

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 0; i < size; i++)
    {
        int n;
        cin >> n;

        if (dp[n] != 0)
        {
            cout << dp[n] << '\n';
            continue;
        }

        for (int j = 4; j <= n; j++)
        {
            dp[j] = dp[j - 2] + dp[j - 3];
        }

        cout << dp[n] << '\n';
    }

    return 0;
}