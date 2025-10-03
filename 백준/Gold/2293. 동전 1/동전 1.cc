#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    // 입력
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);

    // dp[i] = i원을 만드는 경우의 수
    vector<int> dp(k + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    // dp[0] = 아무 동전도 사용하지 않고 0원을 만드는 경우 1가지
    dp[0] = 1;

    for (int coin : coins)
    {
        for (int i = coin; i <= k; i++)
        {
            dp[i] += dp[i - coin];
        }
    }
    
    cout << dp[k];

    return 0;
}