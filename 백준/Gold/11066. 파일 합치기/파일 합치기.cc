#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;

        vector<int> files(K + 1);
        vector<int> prefix(K + 1, 0);

        for (int i = 1; i <= K; i++) {
            cin >> files[i];
            prefix[i] = prefix[i - 1] + files[i];
        }

        // dp[i][j] : i~j 구간 파일을 합치는 최소 비용
        vector<vector<int>> dp(K + 1, vector<int>(K + 1, 0));

        // 구간 길이 len = 2부터 시작
        for (int len = 2; len <= K; len++) {
            for (int i = 1; i + len - 1 <= K; i++) {
                int j = i + len - 1;
                dp[i][j] = INF;

                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j],
                                   dp[i][k] + dp[k + 1][j] + (prefix[j] - prefix[i - 1]));
                }
            }
        }

        cout << dp[1][K] << "\n";
    }

    return 0;
}