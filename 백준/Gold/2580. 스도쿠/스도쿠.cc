#include <iostream>
#include <vector>
using namespace std;

int board[9][9];
vector<pair<int, int>> empty_cells;

bool is_valid(int y, int x, int num) {
    // 행, 열 검사
    for (int i = 0; i < 9; i++) {
        if (board[y][i] == num || board[i][x] == num)
            return false;
    }
    // 3x3 검사
    int sy = (y / 3) * 3;
    int sx = (x / 3) * 3;
    for (int i = sy; i < sy + 3; i++) {
        for (int j = sx; j < sx + 3; j++) {
            if (board[i][j] == num)
                return false;
        }
    }
    return true;
}

void solve(int idx) {
    if (idx == empty_cells.size()) {
        // 스도쿠 완성됐으면 출력하고 종료
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << board[i][j] << ' ';
            cout << '\n';
        }
        exit(0);
    }

    int y = empty_cells[idx].first;
    int x = empty_cells[idx].second;

    for (int num = 1; num <= 9; num++) {
        if (is_valid(y, x, num)) {
            board[y][x] = num;
            solve(idx + 1);
            board[y][x] = 0;
        }
    }
}

int main() {
    // 입력 받기
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0)
                empty_cells.push_back({i, j});
        }
    }

    // 백트래킹 시작
    solve(0);

    return 0;
}