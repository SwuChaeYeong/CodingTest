#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n;
    cin >> n;

    vector<int> dpIn(n, 1);
    vector<int> dpDe(n, 1);
    vector<int> input(n);

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    // 증가
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (input[j] < input[i])
                dpIn[i] = max(dpIn[i], dpIn[j] + 1);
        }
    }

    // 감소 (뒤에서부터 증가하는 걸 찾으면, 앞에서부터는 감소함)
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
            if (input[j] < input[i])
                dpDe[i] = max(dpDe[i], dpDe[j] + 1);
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result = max(result, dpIn[i] + dpDe[i] - 1);
    }

    cout << result;

    return 0;
}