#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;

    int line;

    for (line = 1; num > line; line++)
    {
        num -= line;
    }

    if (line % 2)
        cout << line + 1 - num << "/" << num;
    else
        cout << num << "/" << line + 1 - num;
}