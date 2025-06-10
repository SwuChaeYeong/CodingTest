#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> input(n);

    for (int i = 0; i < n; i++)
        cin >> input[i];

    int windowSum = 0;
    for (int i = 0; i < m; i++)
        windowSum += input[i];

    int maxSum = windowSum;

    for (int i = m; i < n; i++)
    {
        windowSum += input[i] - input[i - m];
        if (windowSum > maxSum)
            maxSum = windowSum;
    }

    cout << maxSum;

    return 0;
}