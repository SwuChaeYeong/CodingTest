#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N;
    cin >> N;

    vector<pair<double, double>> star(N);

    for (int i = 0; i < N; i++)
    {
        cin >> star[i].first >> star[i].second;
    }

    vector<bool> visited(N, false);

    // 비용, 정점
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

    // 시작점
    pq.push({ 0.0, 0 });

    double result = 0.0;
    int cnt = 0;

    while (!pq.empty())
    {
        double cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        // 방문한 경우 패스
        if (visited[now])
            continue;

        // 방문 처리
        visited[now] = true;
        result += cost;
        cnt++;

        // 전부 방문할 경우 종료
        if (cnt == N)
            break;

        // 현재 정점에서 갈 수 있는 모든 정점
        for (int next = 0; next < N; next++)
        {
            if (!visited[next])
            {
                double dx = star[now].first - star[next].first;
                double dy = star[now].second - star[next].second;
                double dist = sqrt(dx * dx + dy * dy);

                pq.push({ dist, next });
            }
        }
    }

    printf("%.2f", result);

    return 0;
}