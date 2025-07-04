#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
long long N;

struct Matrix
{
    long long m[2][2];
};

// 행렬 곱셈
Matrix mul(const Matrix& A, const Matrix& B)
{
    Matrix result = { 0 };

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            // 연산 횟수는 2번 만큼
            for (int k = 0; k < 2; k++)
            {
                result.m[i][j] = (result.m[i][j] + A.m[i][k] * B.m[k][j] % MOD) % MOD;
            }
        }
    }

    return result;
}

// 분할 정복 거듭제곰
Matrix pow(Matrix A, long long b)
{
    // 단위 행렬 초기화
    Matrix result = { 1,0,0,1 };

    // b가 0보다 클동안
    while (b > 0)
    {
        if (b & 1) // b의 0번째 비트가 1이면 (홀수이면
            result = mul(result, A);

        A = mul(A, A);
        b >>= 1;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    // N 입력
    cin >> N;

    if (N == 1 || N == 2)
    {
        cout << 1;
        return 0;
    }

    // 행렬 입력
    Matrix A = { 1,1,1,0 };

    Matrix answer = pow(A, N - 1);

    cout << answer.m[0][0];

    return 0;
}