#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> input(N);

    for (int i = 0; i < N; i++)
    {
        cin >> input[i];
    }

    int result = 0;

    for (int i = N - 1; i >= 0; i--)
    {
        if (K == 0)
            break;

        while (input[i] <= K)
        {
            K -= input[i];
            result++;
        }
    }

    cout << result;

    return 0;
}