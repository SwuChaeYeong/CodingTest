#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> lines(n);
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++)
    {
        cin >> lines[i].first >> lines[i].second;
    }

    sort(lines.begin(), lines.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (lines[j].second < lines[i].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << n - *max_element(dp.begin(), dp.end());

    return 0;
}