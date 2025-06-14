#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n, m, size = 8;
    cin >> n >> m;

    vector<string> board(n);

    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    int temp1 = 0, temp2 = 0;
    int cnt = 65;

    for (int i = 0; i <= n - size; i++)
    {
        for (int j = 0; j <= m - size; j++)
        {
            for (int x = i; x < i + 8; x++)
            {
                for (int y = j; y < j + 8; y++)
                {
                    if ((x - i + y - j) % 2 == 0)
                    {
                        if (board[x][y] != 'W')
                            temp1++;
                    }
                    else
                    {
                        if (board[x][y] != 'B')
                            temp1++;
                    }
                }
            }

            for (int x = i; x < i + 8; x++)
            {
                for (int y = j; y < j + 8; y++)
                {
                    if ((x - i + y - j) % 2 == 0)
                    {
                        if (board[x][y] != 'B')
                            temp2++;
                    }
                    else
                    {
                        if (board[x][y] != 'W')
                            temp2++;
                    }
                }
            }

            cnt = min({ cnt, temp1, temp2 });
            temp1 = 0, temp2 = 0;
        }
    }

    cout << cnt;

    return 0;
}