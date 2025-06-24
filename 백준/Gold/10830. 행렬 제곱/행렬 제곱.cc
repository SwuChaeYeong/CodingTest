#include <iostream>
#include <vector>
using namespace std;

using Matrix = vector<vector<int>>;
const int MOD = 1000;
int N;

// 행렬 곱셈
Matrix mul(const Matrix& A, const Matrix& B)
{
    Matrix result(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // 연산 횟수는 M번 만큼
            for (int k = 0; k < N; k++)
            {
                result[i][j] += (A[i][k] * B[k][j]) % MOD;
            }
            // 더하고 나서 1000이 넘을 수도 있음
            result[i][j] %= MOD;
        }
    }

    return result;
}

// 분할 정복 거듭제곰
Matrix pow(Matrix A, long long b)
{
    // 단위 행렬 초기화
    Matrix result(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        result[i][i] = 1;
    
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
    
    // N, B 입력
    long long B;
    cin >> N >> B;

    // 행렬 입력
    Matrix A(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }

    Matrix answer = pow(A, B);

    // 행렬 출력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}