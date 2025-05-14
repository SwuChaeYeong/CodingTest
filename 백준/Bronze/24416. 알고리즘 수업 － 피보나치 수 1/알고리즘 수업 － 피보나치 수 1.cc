#include <iostream>
using namespace std;

int memo[41];
int cnt = 0;

int fibonacci(int n)
{
    if (n <= 2) return 1;

    // 이미 계산되어 저장된 값이면 반환
    if (memo[n] != 0) return memo[n];

    cnt++;
    return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n;
    cin >> n;

    cout << fibonacci(n) << " " << cnt;

    return 0;
}