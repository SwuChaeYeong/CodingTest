#include <iostream>
#include <deque>
#include <vector>

using namespace std;

const int MAX = 100000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> dist(MAX + 1, -1);
    deque<int> dq;

    dist[N] = 0;
    dq.push_back(N);

    while (!dq.empty())
    {
        int cur = dq.front();
        dq.pop_front();

        if (cur == K)
        {
            cout << dist[cur] << '\n';
            return 0;
        }

        // 1. 순간이동(0초)
        int next = cur * 2;
        if (next <= MAX && dist[next] == -1)
        {
            dist[next] = dist[cur];
            dq.push_front(next);
        }

        // 2. X-1 (1초)
        next = cur - 1;
        if (next >= 0 && dist[next] == -1)
        {
            dist[next] = dist[cur] + 1;
            dq.push_back(next);
        }

        // 3. X+1 (1초)
        next = cur + 1;
        if (next <= MAX && dist[next] == -1)
        {
            dist[next] = dist[cur] + 1;
            dq.push_back(next);
        }
    }

    return 0;
}