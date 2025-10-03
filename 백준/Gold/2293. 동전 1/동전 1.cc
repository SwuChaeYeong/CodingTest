#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 추는 최대 500g, 30개니까 최대 무게 차이는 15000
const int MAX_WEIGHT = 15000;
// i번째 추까지 고려했을 때 w를 만들 수 있는지
bool dp[31][MAX_WEIGHT + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    // 입력
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);

    // dp[i] = i원을 만드는 경우의 수
    vector<int> dp(k + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];

        // 초기화
        // dp[coins[i]] = 1;
    }

    dp[0] = 1;

    for (int coin : coins)
    {
        for (int i = coin; i <= k; i++)
        {
            dp[i] = dp[i] + dp[i - coin];
        }
    }
    
    cout << dp[k];

    return 0;
}