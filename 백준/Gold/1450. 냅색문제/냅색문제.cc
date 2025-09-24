#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> arr;

// 부분집합 합 구하는 함수
void makeSubSums(int start, int end, vector<long long>& subs) {
    int size = end - start;
    for (int mask = 0; mask < (1 << size); mask++) {
        long long sum = 0;
        for (int i = 0; i < size; i++) {
            if (mask & (1 << i)) sum += arr[start + i];
        }
        subs.push_back(sum);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> C;
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    // 반으로 나눠서 부분집합 합 구하기
    vector<long long> left, right;
    makeSubSums(0, N / 2, left);
    makeSubSums(N / 2, N, right);

    sort(right.begin(), right.end());

    long long ans = 0;
    for (long long s : left) {
        if (s > C) continue;
        ans += upper_bound(right.begin(), right.end(), C - s) - right.begin();
    }

    cout << ans << "\n";
    return 0;
}