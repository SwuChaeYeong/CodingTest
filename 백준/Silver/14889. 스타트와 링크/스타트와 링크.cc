#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int s[21][21];
bool visited[21];
int answer = 1e9;


void dfs(int idx, int count)
{
    if (count == n / 2)
    {
        int sTeam = 0, lTeam = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i] && visited[j])
                {
                    sTeam += s[i][j];
                }
                else if (!visited[i] && !visited[j])
                {
                    lTeam += s[i][j];
                }
            }
        }

        int dif = abs(sTeam - lTeam);
        answer = min(answer, dif);
        return;
    }

    for (int i = idx; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(i + 1, count + 1);
            visited[i] = false;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> s[i][j];
        }
    }

    dfs(0, 0);
    cout << answer;

    return 0;
}