#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// 테스트 케이스
int K;
vector<vector<int>> graph;
// 0 미방문, 1, -1
vector<int> bipartite;


int BFS(int start)
{
    queue<int> q;
    q.push(start);
    // 시작
    bipartite[start] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur])
        {
            // 방문 안한 경우
            if (bipartite[next] == 0)
            {
                // 반대로
                bipartite[next] = -bipartite[cur];
                q.push(next);
            }
            else if (bipartite[next] == bipartite[cur])
            {
                // 같은 색 만나면 이분 그래프 아님
                return false;
            }
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    cin >> K;

    for (int i = 0; i < K; i++)
    {
        int V, E;
        cin >> V >> E;

        // 비우고 리사이즈 clear + resize
        graph.assign(V + 1, {});
        bipartite.assign(V + 1, 0);

        for (int i = 0; i < E; i++)
        {
            int a, b;
            cin >> a >> b;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        bool isBipartite = true;

        for (int i = 1; i <= V; i++)
        {
            if (bipartite[i] == 0)
            {
                if (!BFS(i))
                {
                    isBipartite = false;
                    break;
                }
            }
        }

        cout << (isBipartite ? "YES" : "NO") << '\n';
    }
      
    return 0;
}