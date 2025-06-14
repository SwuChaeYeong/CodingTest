#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<string> board(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> board[i];
        board[i] = " " + board[i];  // 인덱스 1로 맞춰줌
    }

    vector<vector<int>> diffW(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> diffB(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // W로 시작하는 경우
            char startW = ((i + j) % 2 == 0) ? 'W' : 'B';
            // B로 시작하는 경우
            char startB = ((i + j) % 2 == 0) ? 'B' : 'W';

            if (board[i][j] != startW)
                diffW[i][j] = 1;

            if (board[i][j] != startB)
                diffB[i][j] = 1;
        }
    }

    // 누적합 계산
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            diffW[i][j] += diffW[i - 1][j] + diffW[i][j - 1] - diffW[i - 1][j - 1];
            diffB[i][j] += diffB[i - 1][j] + diffB[i][j - 1] - diffB[i - 1][j - 1];
        }
    }

    // 정답 계산
    int cnt = 1e9;
    for (int i = k; i <= n; i++)
    {
        for (int j = k; j <= m; j++)
        {
            int cntW = diffW[i][j] - diffW[i - k][j] - diffW[i][j - k] + diffW[i - k][j - k];
            int cntB = diffB[i][j] - diffB[i - k][j] - diffB[i][j - k] + diffB[i - k][j - k];
            cnt = min({ cnt, cntW, cntB });
        }
    }

    cout << cnt;

    return 0;
}