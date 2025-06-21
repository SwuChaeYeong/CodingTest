#include <iostream>
using namespace std;

const int MOD = 1000000007;

// 거듭제곱 모듈러
long long power(long long a, long long b) {
    long long result = 1;
    while (b) {
        if (b & 1) result = result * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    long long N, K;
    cin >> N >> K;

    if (K == 0 || K == N) {
        cout << 1;
        return 0;
    }

    long long num = 1, den = 1;

    for (long long i = 0; i < K; i++) {
        num = num * (N - i) % MOD;
        den = den * (i + 1) % MOD;
    }

    long long result = num * power(den, MOD - 2) % MOD;
    cout << result;

    return 0;
}