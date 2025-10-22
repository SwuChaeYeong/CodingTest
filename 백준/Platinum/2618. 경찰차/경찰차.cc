#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, W;
vector<pair<int, int>> events;  // 사건 좌표
// dp[i][j] = 1번 경찰차가 i번째 사건, 2번 경찰차가 j번째 사건을 마지막으로 처리했을 때 최소 이동 거리
int dp[1001][1001];
int choice[1001][1001]; // 경로 추적

// 거리 계산 함수
int dist(int from, int to, int car)
{
    int x1, y1;

    // 시작점
    if (from == 0)
    {
        if (car == 1)
        {
            x1 = 1;
            y1 = 1;
        }
        else
        {
            x1 = N;
            y1 = N;
        }
    }
    else
    {
        x1 = events[from - 1].first;
        y1 = events[from - 1].second;
    }

    int x2 = events[to - 1].first;
    int y2 = events[to - 1].second;

    return abs(x1 - x2) + abs(y1 - y2);
}

int solve(int i, int j)
{
    // 다음 사건 번호
    int next = max(i, j) + 1;
    // 모든 사건 처리 끝
    if (next > W)return 0;

    int& ret = dp[i][j];
    if (ret != -1)
        return ret;

    // 1번 차가 next 처리
    int cost1 = solve(next, j) + dist(i, next, 1);
    // 2번 차가 next 처리
    int cost2 = solve(i, next) + dist(j, next, 2);

    if (cost1 < cost2)
    {
        ret = cost1;
        choice[i][j] = 1;
    }
    else
    {
        ret = cost2;
        choice[i][j] = 2;
    }

    return ret;
}

void track(int i, int j)
{
    int next = max(i, j) + 1;
    if (next > W)
        return;

    if (choice[i][j] == 1)
    {
        cout << 1 << '\n';
        track(next, j);
    }
    else
    {
        cout << 2 << '\n';
        track(i, next);
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    cin >> N >> W;
    events.resize(W);

    for (int i = 0; i < W; i++)
    {
        cin >> events[i].first >> events[i].second;
    }

    // dp 초기화
    for (int i = 0; i <= W; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << solve(0, 0) << '\n';
    track(0, 0);

    return 0;
}