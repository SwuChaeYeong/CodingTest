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

    // dp[x] = x를 1로 만들기 위한 최소 연산 횟수
    vector<int> dp(N + 1, 0);
    // prev[x] = x로 오기 직전 숫자 (경로 추적)
    vector<int> prev(N + 1, 0);

    for (int i = 2; i <= N; i++)
    {
        // 1을 빼는 경우
        dp[i] = dp[i - 1] + 1;
        prev[i] = i - 1;

        // 2로 나눌 수 있는 경우
        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
        {
            dp[i] = dp[i / 2] + 1;
            prev[i] = i / 2;
        }

        // 3으로 나눌 수 있는 경우
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
        {
            dp[i] = dp[i / 3] + 1;
            prev[i] = i / 3;
        }
    }

    // 최소 연산 횟수 출력
    cout << dp[N] << '\n';

    // 경로 복원
    vector<int> path;
    for (int cur = N; cur != 0; cur = prev[cur])
    {
        path.push_back(cur);
        if (cur == 1)
            break;
    }

    for (int x : path)
        cout << x << " ";

    cout << "\n";

    return 0;
}