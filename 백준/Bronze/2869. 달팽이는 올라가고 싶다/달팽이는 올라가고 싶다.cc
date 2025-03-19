#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int up, down, des;
    cin >> up >> down >> des;

    int dayUp = up - down;
    int desMin = des - up;

    int day = ceil((double)desMin / dayUp) + 1;

    cout << day;

    return 0;
}