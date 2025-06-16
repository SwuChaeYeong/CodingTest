#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n;
    cin >> n;

    int currentSum, maxSum;
    cin >> currentSum;

    maxSum = currentSum;

    for (int i = 0; i < n - 1; i++)
    {
        int temp;
        cin >> temp;

        // 새로 연속합을 시작할지 계속 이어갈지
        currentSum = max(temp, currentSum + temp);
        maxSum = max(maxSum, currentSum);
    }

    cout << maxSum;

    return 0;
}