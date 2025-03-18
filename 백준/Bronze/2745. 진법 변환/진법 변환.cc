#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int format;
    string num;

    cin >> num >> format;

    int format10 = 0;

    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] < 58)
            format10 += pow(format, num.size() - i - 1) * (num[i] - '0');
        else if (num[i] < 91)
            format10 += pow(format, num.size() - i - 1) * (num[i] - 55);
    }

    cout << format10;

    return 0;
}