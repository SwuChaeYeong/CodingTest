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

    int fr1D, fr1N, fr2D, fr2N, resultD, resultN, gcd;

    cin >> fr1N >> fr1D;
    cin >> fr2N >> fr2D;

    //최소공배수(분모)
    resultD = fr1D * fr2D / Gcd(fr1D, fr2D);

    //합(분자)
    resultN = resultD / fr1D * fr1N + resultD / fr2D * fr2N;

    //최대공약수
    gcd = Gcd(resultD, resultN);

    cout << resultN / gcd << " " << resultD / gcd;

    return 0;
}