#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n;
    cin >> n;

    vector<int> v;
    vector<int> input(n);

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(v.begin(), v.end(), input[i]);

        if (it == v.end())
            v.push_back(input[i]);
        else
            *it = input[i];
    }

    cout << v.size();

    return 0;
}