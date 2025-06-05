#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> w(n);
    vector<int> v(n);
    vector<int> dp(k + 1, 0);

    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = k; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }

    cout << dp[k];

    return 0;
}