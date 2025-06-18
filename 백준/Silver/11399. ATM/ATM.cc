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

    int result = 0, sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += t[i];
        result += sum;
    }

    cout << result;

    return 0;
}