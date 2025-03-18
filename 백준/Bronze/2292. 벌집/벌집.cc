#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;

    int result = 1;

    if (num > 1) {
        for (int i = 6; num > 1; i += 6)
        {
            result++;
            num -= i;
        }
    }

    cout << result;

    return 0;
}