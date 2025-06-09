#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> input(n);
    vector<int> psum(n + 1, 0);

    for (int i = 0; i < n; i++)
        cin >> input[i];

    for (int i = 1; i <= n; i++)
    {
        psum[i] = psum[i - 1] + input[i - 1];
    }

    int j, k;
    for (int i = 0; i < m; i++)
    {
        cin >> j >> k;
        cout << psum[k] - psum[j - 1] << '\n';
    }

    return 0;
}