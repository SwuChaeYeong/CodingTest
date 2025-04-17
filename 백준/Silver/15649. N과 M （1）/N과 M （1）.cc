#include <iostream>
using namespace std;

int n, m;
int num[9];
bool visited[9];

void DFS(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << num[i] << " ";
        }
        cout << "\n";
        return;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == false)
            {
                visited[i] = true;
                num[cnt] = i;

                DFS(cnt + 1);
                visited[i] = false;
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    cin >> n >> m;
    DFS(0);

    return 0;
}