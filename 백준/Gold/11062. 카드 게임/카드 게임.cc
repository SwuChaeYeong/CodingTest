#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> card;
// dp[l][r] = 구간 [l, r]에서 근우가 얻을 수 있는 최대 점수
int dp[1001][1001];
bool visited[1001][1001];

int solve(int l, int r)
{
    if (l > r)
        return 0;

    // 이미 계산된 경우
    if (visited[l][r])
        return dp[l][r];

    visited[l][r] = true;
    int turn = (N - (r - l + 1)) % 2;

    if (turn == 0)
    {
        dp[l][r] = max(card[l] + solve(l + 1, r), card[r] + solve(l, r - 1));
    }
    else
    {
        dp[l][r] = min(solve(l + 1, r), solve(l, r - 1));
    }

    return dp[l][r];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        cin >> N;
        card.resize(N);

        for (int i = 0; i < N; i++)
            cin >> card[i];

        // dp 초기화
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                visited[i][j] = false;
        }

        cout << solve(0, N - 1) << '\n';
    }

    return 0;
}