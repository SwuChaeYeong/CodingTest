#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N;
    cin >> N;

    vector<int> city(N - 1);
    vector<int> oil(N);

    for (int i = 0; i < N - 1; i++)
        cin >> city[i];

    for (int i = 0; i < N; i++)
        cin >> oil[i];

    long long result = 0;
    long long price = oil[0];

    for (int i = 0; i < N - 1; i++)
    {
        result += price * city[i];

        if (price > oil[i + 1])
            price = oil[i + 1];

    }

    cout << result;

    return 0;
}