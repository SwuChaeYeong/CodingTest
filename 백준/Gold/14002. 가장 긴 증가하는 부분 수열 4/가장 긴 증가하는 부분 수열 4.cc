#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    // dp[x] = x까지 고려했을때 가장 긴 증가하는 부분 수열의 길이
    vector<int> dp(N + 1, 1);
    // prev[x] = x로 오기 직전 숫자 (경로 추적)
    vector<int> prev(N + 1, -1);

    int maxLen = 1;
    int lastIndex = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j]<A[i] && dp[j] + 1>dp[i])
            {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > maxLen)
        {
            maxLen = dp[i];
            lastIndex = i;
        }
    }

    cout << maxLen << '\n';

    // 경로 복원
    vector<int> path;
    for (int cur = lastIndex; cur != -1; cur = prev[cur])
    {
        path.push_back(A[cur]);
    }

    reverse(path.begin(), path.end());

    for (int x : path)
        cout << x << " ";

    cout << "\n";

    return 0;
}