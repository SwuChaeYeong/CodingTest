#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;

const int MAX = 100001;

// 맵 입력
vector<string> map;

// 각 정점 방문 순서 저장
bool visited[MAX];
// 각 정점에 도달했을 때 거리
int dist[MAX];

void BFS(int index)
{
    // 큐에 삽입 (방문 처리)
    queue<int> q;
    q.push(index);

    visited[index] = true;
    dist[index] = 0;

    // 큐가 빌 때까지
    while (!q.empty())
    {
        // 큐에서 꺼냄 (해당 노드에 도달)
        int now = q.front();
        q.pop();

        if (now == K)
        {
            cout << dist[now];
            return;
        }

        for (int next : {now - 1, now + 1, now * 2})
        {
            // 이동할 수 있는 경로고, 방문하지 않은 경우
            if (next >= 0 && next < MAX && !visited[next])
            {
                // 방문 처리
                visited[next] = true;
                // 이전 경로에서 +1
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    // 수빈이와 동생 위치
    cin >> N >> K;

    // BFS (최단거리)
    BFS(N);
      
    return 0;
}