#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n;
    cin >> n;

    vector<int> dp(n, 1);
    vector<int> input(n);

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (input[j] < input[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int result = *max_element(dp.begin(), dp.end());
    cout << result;

    return 0;
}