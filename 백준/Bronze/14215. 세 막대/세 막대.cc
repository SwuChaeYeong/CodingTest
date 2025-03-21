#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int line[3];
    cin >> line[0] >> line[1] >> line[2];

    sort(line, line + 3);

    //삼각형이 안 만들어지는 경우
    if ((line[0] + line[1] + line[2]) <= line[2] * 2)
        cout << (line[0] + line[1]) * 2 - 1;
    else
        cout << line[0] + line[1] + line[2];

    return 0;
}