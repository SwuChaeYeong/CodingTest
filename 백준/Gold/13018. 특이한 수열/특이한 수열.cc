#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, K;
    cin >> N >> K;

    // K == N인 경우 불가능
    if (K == N) {
        cout << "Impossible";
        return 0;
    }

    // 기본적으로 1 ~ N으로 수열 초기화
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        A[i] = i;
    }

    // 만족하지 않는 개수 R
    long long R = (N - 1) - K;

    // 가능한 만큼 인접 스왑 (2씩 감소)
    for (int i = 2; i <= N && R >= 2; i += 2) {
        swap(A[i], A[i + 1]);
        R -= 2;
    }

    // 1 남으면 1과 N을 스왑
    if (R == 1) {
        swap(A[1], A[N]);
    }

    // 출력
    for (int i = 1; i <= N; i++) {
        cout << A[i] << (i < N ? ' ' : '\n');
    }
    return 0;
}