#include <iostream>
#include <cmath>
using namespace std;

int n;
int visit[15] = { 0, };
int result = 0;


bool isPossible(int num)
{
    for (int i = 0; i < num; i++)
    {
        if (visit[num] == visit[i] || abs(num - i) == abs(visit[num] - visit[i]))
            return false;
    }

    return true;
}

void Queen(int idx)
{
    if (idx == n)
    {
        result++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        visit[idx] = i;

        if (isPossible(idx))
        {
            Queen(idx + 1);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    cin >> n;

    Queen(0);

    cout << result;

    return 0;
}