#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1001;

// 토마토
int tomato[MAX][MAX];
// 각 정점 방문 순서 저장
bool visited[MAX][MAX];
// 각 정점에 도달했을 때 거리
int day[MAX][MAX];

int dirRow[4] = { 1, -1, 0, 0 };
int dirCol[4] = { 0, 0, 1, -1 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int row, col;
    cin >> col >> row;

    queue<pair<int, int>> q;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> tomato[i][j];

            // 익은 것들 전부 큐에 삽입
            if (tomato[i][j] == 1)
            {
                q.push({ i, j });
            }
        }
    }

    // 큐가 빌 때까지
    while (!q.empty())
    {
        // 큐에서 꺼냄 (해당 노드에 도달)
        int cRow = q.front().first;
        int cCol = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nRow = cRow + dirRow[dir];
            int nCol = cCol + dirCol[dir];

            // 이동할 수 있는 경로고, 방문하지 않은 경우
            if (nRow >= 0 && nRow < row && nCol >=0 && nCol < col)
            {   
                // 토마토가 익지 않았으면
                if (tomato[nRow][nCol] == 0)
                {
                    // 토마토 익음
                    tomato[nRow][nCol] = 1;
                    // 이전 경로에서 +1
                    day[nRow][nCol] = day[cRow][cCol] + 1;
                    // 익었으니까 큐에 삽입
                    q.push({ nRow, nCol });
                }
            }
        }
    }

    int result = 0;

    // 연산 다 끝나고 나면
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // 안 익은 게 있으면
            if (tomato[i][j] == 0)
            {
                cout << -1;
                return 0;
            }

            result = max(result, day[i][j]);
        }
    }

    cout << result;
      
    return 0;
}