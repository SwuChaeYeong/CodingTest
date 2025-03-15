#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char str[1001];
    cin >> str;

    int num;
    cin >> num;

    cout << str[num - 1];

    return 0;
}