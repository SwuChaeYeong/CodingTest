#include <iostream>
#include <set>
#include <string>

using namespace std;

int Gcd(int a, int b)
{
    int remain = a % b;

    if (remain == 0)
        return b;
    else
        return Gcd(b, remain);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d, denominator, numerator, gcd;

    cin >> a >> b;
    cin >> c >> d;

    numerator = (b * c) + (a * d);
    denominator = b * d;

    //최대공약수
    gcd = Gcd(numerator, denominator);

    cout << numerator / gcd << " " << denominator / gcd;

    return 0;
}