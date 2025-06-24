#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    // 행렬 입력

    int N, M, K;
    cin >> N >> M;

    vector<vector<int>> matrixA(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> matrixA[i][j];
        }
    }

    cin >> M >> K;

    vector<vector<int>> matrixB(M, vector<int>(K));

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < K; j++)
        {
            cin >> matrixB[i][j];
        }
    }

    // 행렬 곱
    // NxM 행렬 A와 MxK 행렬 B의 곱은 NxK 행렬
    vector<vector<int>> matrixR(N, vector<int>(K, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            // 연산 횟수는 M번 만큼
            for (int k = 0; k < M; k++)
            {
                matrixR[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    // 행렬 출력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            cout << matrixR[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}