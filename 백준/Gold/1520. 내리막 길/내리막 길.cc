#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C;
vector<vector<int>> board;
vector<vector<int>> dp;

// 방향
int dc[4] = { -1,1,0,0 };
int dr[4] = { 0,0,-1,1 };

int DFS(int row, int col)
{
    // 도착점이면 경로 1개
    if (row == R - 1 && col == C - 1)
        return 1;

    // 이미 계산된 값이 있으면 반환
    if (dp[row][col] != -1)
        return dp[row][col];

    // 새로운 탐색 시작
    dp[row][col] = 0;

    // 4방향 탐색
    for (int dir = 0; dir < 4; dir++)
    {
        int nr = row + dr[dir];
        int nc = col + dc[dir];

        // 범위 내인지 확인
        if (nr >= 0 && nr < R && nc >= 0 && nc < C)
        {
            // 더 작으면
            if (board[nr][nc] < board[row][col])
            {
                dp[row][col] += DFS(nr, nc);
            }
        }
    }

    return dp[row][col];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    // 입력
    cin >> R >> C;

    board.assign(R, vector<int>(C));
    dp.assign(R, vector<int>(C, -1));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> board[i][j];
        }
    }

    cout << DFS(0, 0);
    
    return 0;
}