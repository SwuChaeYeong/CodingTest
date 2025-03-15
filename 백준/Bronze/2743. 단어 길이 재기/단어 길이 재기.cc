#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char str[101];
    cin >> str;

    for (int i = 0; i < 101; i++) {
        if (str[i] == NULL) {
            cout << i;
            break;
        }
    }

    return 0;
}