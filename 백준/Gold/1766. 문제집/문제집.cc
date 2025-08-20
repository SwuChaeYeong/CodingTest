#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    // 문제 개수
    int N, M;
    cin >> N >> M;

    // 차수
    vector<int> indegree(N + 1, 0);
    // 인접 행렬
    vector<vector<int>> adj(N + 1);

    // 그래프 생성
    while (M--)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        indegree[b]++;
    }

    // 최소 힙 (번호가 작은 문제부터 나오도록 함)
    priority_queue<int, vector<int>, greater<int>> pq;

    // 진입 차수가 0인 문제들 push
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
            pq.push(i);
    }

    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();

        cout << cur << " ";

        for (int next : adj[cur])
        {
            indegree[next]--;
            if (indegree[next] == 0)
                pq.push(next);
        }
    }

    return 0;
}