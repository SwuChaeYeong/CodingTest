#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N, M;
    cin >> N >> M;

    // n x n 거리 행렬 초기화
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));
    // 경로 복원용
    vector<vector<int>> nxt(N + 1, vector<int>(N + 1, 0));

    // 자기 자신의 거리 0
    for (int i = 1; i <= N; i++)
        dist[i][i] = 0;

    // 간선 입력
    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        // 같은 간선이 여러 번 들어올 수 있으므로 최소 비용만 반영
        if (w < dist[u][v])
        {
            dist[u][v] = w;
            // 직접 간선이면 다음 정점은 v
            nxt[u][v] = v;
        }
    }
    
    // 플로이드 워셜 알고리즘
    for (int k = 1; k <= N; k++)            // 경유지
    {
        for (int i = 1; i <= N; i++)        // 출발지
        {
            if (dist[i][k] == INF)
                continue;

            for (int j = 1; j <= N; j++)    // 도착지
            {
                if (dist[k][j] == INF)
                    continue;

                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    // i->j 경로의 다음 정점은 i->k의 다음 정점
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    // 출력
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (dist[i][j] == INF)
                cout << 0 << " ";

            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    // 경로 출력
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            // 본인 > 본인으로 가거나
            // 갈 수 있는 경로가 없는 경우
            if (i == j || dist[i][j] == INF)
            {
                cout << 0 << '\n';
                continue;
            }

            // 경로 복원
            vector<int> path;
            int cur = i;
            path.push_back(cur);

            while (cur != j)
            {
                cur = nxt[cur][j];

                // 만약 nxt가 0이면 경로가 없음
                if (cur == 0)
                {
                    path.clear();
                    break;
                }
                path.push_back(cur);
            }

            if (path.empty())
                cout << 0 << '\n';

            else
            {
                cout << path.size();

                for (int v : path)
                    cout << ' ' << v;

                cout << '\n';
            }
                    
        }
    }

    return 0;
}