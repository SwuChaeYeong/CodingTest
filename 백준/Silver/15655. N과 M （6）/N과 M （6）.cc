#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int num[9];
int input[9];

void DFS(int depth, int start)
{
    if (depth == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i < n; i++)
    {
        num[depth] = input[i];
        DFS(depth + 1, i + 1);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    sort(input, input + n);

    DFS(0, 0);

    return 0;
}