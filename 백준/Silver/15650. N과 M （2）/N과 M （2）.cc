#include <iostream>
using namespace std;

int n, m;
int arr[9];
bool visited[9];

void DFS(int num, int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    else
    {
        for (int i = num; i <= n; i++)
        {
            if (visited[i] == false)
            {
                visited[i] = true;
                arr[cnt] = i;

                DFS(i+1, cnt + 1);
                visited[i] = false;
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    cin >> n >> m;
    DFS(1, 0);

    return 0;
}