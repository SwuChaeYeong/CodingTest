#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int format;
    int num;

    cin >> num >> format;

    string formatN;

    int quot = num;
    int remain = 0;

    while (quot >= format) {
        remain = quot % format;
        quot /= format;

        if (remain > 9)
            formatN = (char)(remain + 55) + formatN;
        else
            formatN = to_string(remain) + formatN;
    }

    remain = quot % format;

    if (remain > 9)
        formatN = (char)(remain + 55) + formatN;
    else
        formatN = to_string(remain) + formatN;

    cout << formatN;

    return 0;
}