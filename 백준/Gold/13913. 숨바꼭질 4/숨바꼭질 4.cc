#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100000;
int dist[MAX + 1];  // 이동 시간
int prev_pos[MAX + 1];  // 이전 위치 기록


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N, K;
    cin >> N >> K;

    // 초기화
    for (int i = 0; i <= MAX; i++)
        dist[i] = -1;   // 방문 안 함 표시

    queue<int> q;
    q.push(N);
    dist[N] = 0;
    prev_pos[N] = -1;   // 시작점은 이전 위치 X

    // BFS 시작
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        // 도착하면 종료
        if (cur == K)
            break;

        // 이동 가능한 3가지 경우
        for (int next : {cur - 1, cur + 1, cur * 2})
        {
            if (next < 0 || next > MAX)
                continue;
            
            // 이미 방문한 곳
            if (dist[next] != -1)
                continue;

            dist[next] = dist[cur] + 1;
            prev_pos[next] = cur;   // 어디서 왔는지 저장
            q.push(next);
        }
    }

    // 결과 출력
    cout << dist[K] << '\n';

    // 경로 복원
    vector<int> path;
    for (int i = K; i != -1; i = prev_pos[i])
        path.push_back(i);

    reverse(path.begin(), path.end());

    for (int p : path)
        cout << p << " ";

    return 0;
}