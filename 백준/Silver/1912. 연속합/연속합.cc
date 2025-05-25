#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n;
    cin >> n;

    vector<int> dp(n);
    vector<int> input(n);

    dp.resize(n, 0);
    input.reserve(n);

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    dp[0] = input[0];

    for (int i = 1; i < n; i++)
    {
        dp[i] = max(input[i], input[i] + dp[i - 1]);
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}