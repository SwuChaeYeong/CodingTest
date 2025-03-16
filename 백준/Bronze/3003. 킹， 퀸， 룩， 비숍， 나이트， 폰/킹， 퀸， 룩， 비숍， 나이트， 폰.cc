#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int chess[6] = { 1,1,2,2,2,8 };
    int input[6];

    for (int i = 0; i < 6; i++) {
        cin >> input[i];

        chess[i] -= input[i];

        cout << chess[i] << " ";
    }

    return 0;
}