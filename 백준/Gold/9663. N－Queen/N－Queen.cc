#include <iostream>
#include <cmath>

using namespace std;

int N;
int visit[16] = { 0, };
int result = 0;

// 대각선 계산 후 배치 가능 여부 반환
bool isPossible(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (visit[n] == visit[i] || abs(n - i) == abs(visit[n] - visit[i]))
            return false;
    }

    return true;
}

void queen(int idx)
{
    if (idx == N)
    {
        result++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        visit[idx] = i;

        if (isPossible(idx))
        {
            queen(idx + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    cin >> N;

    queen(0);

    cout << result;

    return 0;
}