#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    // 입력
    int N;
    cin >> N;

    vector<int> r(N + 1), c(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> r[i] >> c[i];
    }

    // dp[i][j] = i번 행렬부터 j번 행렬까지 곱할 때 최소 곱셈 횟수
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, INF));

    // 본인끼리는 곱할 필요 없음
    for (int i = 1; i <= N; i++)
        dp[i][i] = 0;

    // 구간 길이 len = 2 ~ N
    for (int len = 2; len <= N; len++)
    {
        for (int i = 1; i + len - 1 <= N; i++)
        {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + r[i] * c[k] * c[j]);
            }
        }
    }

    cout << dp[1][N];

    return 0;
}