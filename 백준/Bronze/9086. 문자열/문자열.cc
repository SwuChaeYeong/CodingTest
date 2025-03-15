#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;

    char str[1001];

    for (int i = 0; i < num; i++) {
        cin >> str;

        for (int j = 0; j < 1001; j++) {

            if (str[j] == NULL)
            {
                cout << str[0] << str[j - 1] << "\n";
                break;
            }
        }
    }

    return 0;
}