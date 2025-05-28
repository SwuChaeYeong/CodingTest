#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> tri(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cin >> tri[i][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            tri[i][j] += max(tri[i + 1][j], tri[i + 1][j + 1]);
        }
    }

    cout << tri[0][0];

    return 0;
}