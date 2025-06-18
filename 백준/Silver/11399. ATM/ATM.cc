#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N;
    cin >> N;

    vector<int> t(N);

    for (int i = 0; i < N; i++)
    {
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    int result = t[0];
    for (int i = 1; i < N; i++)
    {
        t[i] += t[i - 1];
        result += t[i];
    }

    cout << result;

    return 0;
}