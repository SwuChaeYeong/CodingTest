#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_COST = 10000;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    // 입력
    int N, M;
    cin >> N >> M;

    vector<int> apps(N);
    vector<int> costs(N);

    for (int i = 0; i < N; i++)
    {
        cin >> apps[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> costs[i];
    }

    // dp[i] = 비용 i를 썼을 때 확보 가능한 최대 메모리
    vector<int> dp(MAX_COST + 1, 0);

    for (int i = 0; i < N; i++)
    {
        for (int c = MAX_COST; c >= costs[i]; c--)
        {
            dp[c] = max(dp[c], dp[c - costs[i]] + apps[i]);
        }
    }

    // dp[c] >= M 되는 최소 cost 찾기
    int answer = MAX_COST;
    for (int c = 0; c <= MAX_COST; c++)
    {
        if (dp[c] >= M)
        {
            answer = c;
            break;
        }
    }

    cout << answer;

    return 0;
}