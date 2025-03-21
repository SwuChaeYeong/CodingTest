#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    if (a + b + c != 180)
        cout << "Error";
    else if ((a == b) && (b == c))
        cout << "Equilateral";
    else if ((a != b) && (b != c) && (a != c))
        cout << "Scalene";
    else
        cout << "Isosceles";

    return 0;
}