#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n;
    cin >> n;

    vector<int> input(n);
    vector<int> dp(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    dp[1] = input[0];
    dp[2] = input[0] + input[1];

    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i - 2], dp[i - 3] + input[i - 2]) + input[i - 1];
    }

    cout << dp[n];

    return 0;
}