#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool remain[42] = { false };

    int num;
    int count = 0;

    for (int i = 0; i < 10; i++) {
        cin >> num;
        remain[num % 42] = true;
    }

    for (int i = 0; i < 42; i++) {
        if (remain[i])
            count++;
    }

    cout << count;

    return 0;
}