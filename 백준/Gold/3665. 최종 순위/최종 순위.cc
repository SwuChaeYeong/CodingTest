#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    // 테스트 케이스
    int T;
    cin >> T;

    while (T--)
    {
        // 팀 개수
        int n;
        cin >> n;
        
        // 작년 순위
        vector<int> last(n);

        for (int i = 0; i < n; i++)
        {
            cin >> last[i];
        }

        // 차수
        vector<int> indegree(n + 1, 0);
        // 인접 행렬
        vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));

        // 작년 순위로 그래프 생성
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int highher = last[i], lower = last[j];
                adj[highher][lower] = true;
                indegree[lower]++;
            }
        }

        // 작년과 다른 순위 
        int m;
        cin >> m;

        // 간선 방향 조절
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;

            // 원래 a가 b보다 위였으면
            if (adj[a][b])
            {
                // a -> b 제거하고 b -> a 추가
                adj[a][b] = false;
                adj[b][a] = true;

                // 진입 차수 변경
                indegree[b]--;
                indegree[a]++;
            }
            else
            {
                adj[b][a] = false;
                adj[a][b] = true;

                indegree[a]--;
                indegree[b]++;
            }
        }

        // 위상 정렬
        queue<int> q;

        // 차수가 0이면 삽입
        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> result;
        bool certain = true;
        bool impossible = false;

        for (int i = 0; i < n; i++)
        {
            // 사이클 발생
            if (q.empty())
            {
                impossible = true;
                break;
            }
            // 확정 불가능 (후보가 2개 이상 - 순위가 여러 개 가능)
            if (q.size() > 1)
            {
                certain = false;
            }

            int cur = q.front();
            q.pop();
            result.push_back(cur);

            for (int next = 1; next <= n; next++)
            {
                if (adj[cur][next])
                {
                    indegree[next]--;
                    
                    if (indegree[next] == 0)
                        q.push(next);
                }
            }
        }

        if (impossible) cout << "IMPOSSIBLE\n";
        else if (!certain) cout << "?\n";
        else
        {
            for (int x : result)
                cout << x << " ";

            cout << '\n';
        }
    }

    return 0;
}