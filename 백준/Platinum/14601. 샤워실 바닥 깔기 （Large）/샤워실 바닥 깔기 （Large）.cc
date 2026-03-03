#include <iostream>
using namespace std;

int board[128][128];
int tile_id = 1;

void solve(int sr, int sc, int hole_r, int hole_c, int size)
{
    if (size == 1) return;

    int id = tile_id++;
    int half = size / 2;

    int mid_r = sr + half;
    int mid_c = sc + half;

    int quad;
    if (hole_r < mid_r && hole_c < mid_c) quad = 0;       // 좌상
    else if (hole_r < mid_r && hole_c >= mid_c) quad = 1; // 우상
    else if (hole_r >= mid_r && hole_c < mid_c) quad = 2; // 좌하
    else quad = 3;                                        // 우하

    if (quad != 0) board[mid_r-1][mid_c-1] = id;
    if (quad != 1) board[mid_r-1][mid_c]   = id;
    if (quad != 2) board[mid_r][mid_c-1]   = id;
    if (quad != 3) board[mid_r][mid_c]     = id;

    solve(sr, sc,
          quad == 0 ? hole_r : mid_r-1,
          quad == 0 ? hole_c : mid_c-1,
          half);

    solve(sr, mid_c,
          quad == 1 ? hole_r : mid_r-1,
          quad == 1 ? hole_c : mid_c,
          half);

    solve(mid_r, sc,
          quad == 2 ? hole_r : mid_r,
          quad == 2 ? hole_c : mid_c-1,
          half);

    solve(mid_r, mid_c,
          quad == 3 ? hole_r : mid_r,
          quad == 3 ? hole_c : mid_c,
          half);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> K;

    int N = 1 << K;

    int x, y;
    cin >> x >> y;

    int hole_r = N - y;
    int hole_c = x - 1;

    solve(0, 0, hole_r, hole_c, N);

    board[hole_r][hole_c] = -1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j];
            if (j != N-1) cout << " ";
        }
        cout << "\n";
    }
}