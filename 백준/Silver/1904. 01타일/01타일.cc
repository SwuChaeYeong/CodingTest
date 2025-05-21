#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n;
    cin >> n;

    int n1 = 1, n2 = 2;
    int result;

    if (n <= 2)
    {
        cout << n;
        return 0;
    }

    for (int i = 3; i <= n; i++)
    {
        result = (n1 + n2) % 15746;
        n1 = n2;
        n2 = result;
    }

    cout << result;

    return 0;
}