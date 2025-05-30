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
    vector<int> dp(n);

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    dp[0] = input[0];
    dp[1] = input[1] + input[0];
    dp[2] = max({ input[0] + input[2], input[1] + input[2], dp[1] });

    for (int i = 3; i < n; i++)
    {
        dp[i] = max({ dp[i - 1], dp[i - 2] + input[i], dp[i - 3] + input[i] + input[i - 1] });
    }

    cout << dp[n-1];


    return 0;
}