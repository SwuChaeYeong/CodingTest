#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    int time = 0;

    for (int i = 0; i < str.length(); i++) {
        str[i] -= 'A';

        if (str[i] < 15)
            time = time + 3 + str[i] / 3;
        else if (str[i] < 19)
            time += 8;
        else if (str[i] < 22)
            time += 9;
        else if (str[i] < 26)
            time += 10;
    }

    cout << time;
}