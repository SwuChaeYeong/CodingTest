#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> input(n);
    vector<int> psum(n + 1, 0);
    int result = -1e9;

    for (int i = 0; i < n; i++)
        cin >> input[i];

    for (int i = 1; i <= n; i++)
    {
        psum[i] = psum[i - 1] + input[i - 1];
    }

    for (int i = 0; i <= n - m; i++)
    {
        int temp = psum[i + m] - psum[i];

        if (temp > result)
            result = temp;
    }

    cout << result;

    return 0;
}