#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    string A, B;
    cin >> A >> B;

    int n = A.size();
    int m = B.size();

    // dp[i][j] = A의 i번째까지와 B의 j번째까지 고려했을 때 LCS 길이
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // LCS 길이
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // 결과 문자열
    string lcs = "";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (A[i - 1] == B[j - 1])
        {
            lcs += A[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] >= dp[i][j - 1])
                i--;

            else
                j--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    cout << dp[n][m] << "\n";
    if (!lcs.empty())
        cout << lcs << "\n";

    return 0;
}