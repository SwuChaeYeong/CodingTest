#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

bool visited[101];
unordered_map<int, int> jump;

int BFS()
{
    // 현재 위치, 주사위 굴림 횟수
    queue<pair<int, int>> q;
    q.push({ 1, 0 });
    visited[1] = true;

    while (!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == 100)
            return cnt;

        for (int dice = 1; dice <= 6; dice++)
        {
            int next = cur + dice;

            if (next > 100)
                continue;

            // 사다리에 뱀이 있으면 이동
            if (jump.count(next))
            {
                next = jump[next];
            }

            if (!visited[next])
            {
                visited[next] = true;
                q.push({ next, cnt + 1 });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N, M;
    cin >> N >> M;

    // 사다리 입력
    for (int i = 0; i < N; i++)
    {
        int from, to;
        cin >> from >> to;
        jump[from] = to;
    }

    // 뱀 입력
    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        jump[from] = to;
    }

    cout << BFS();
      
    return 0;
}