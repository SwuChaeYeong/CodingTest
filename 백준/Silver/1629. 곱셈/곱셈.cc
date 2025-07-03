#include <iostream>
#include <vector>
using namespace std;

long long A, B, C;

int mul(long long a, long long b)
{
    if (b == 0)
        return 1;

    long long half = mul(a, b / 2);
    long long result = (half * half) % C;

    if (b % 2 == 0)
        return result;

    else
        return (result * a) % C;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
    
    cin >> A >> B >> C;

    cout << mul(A, B);

    return 0;
}