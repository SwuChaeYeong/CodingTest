#include <iostream>
#include <algorithm>
using namespace std;

int n;
int numbers[11];
int operators[4];  // +, -, *, /
int maxResult = -1e9;
int minResult = 1e9;

void dfs(int depth, int total) {
    if (depth == n) {
        maxResult = max(maxResult, total);
        minResult = min(minResult, total);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (operators[i] > 0) {
            operators[i]--;  // 연산자 사용

            if (i == 0) dfs(depth + 1, total + numbers[depth]);
            else if (i == 1) dfs(depth + 1, total - numbers[depth]);
            else if (i == 2) dfs(depth + 1, total * numbers[depth]);
            else if (i == 3) {
                if (total < 0)  // 음수 나눗셈 처리
                    dfs(depth + 1, -(-total / numbers[depth]));
                else
                    dfs(depth + 1, total / numbers[depth]);
            }

            operators[i]++;  // 연산자 복구 (백트래킹)
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> operators[i];
    }

    dfs(1, numbers[0]);

    cout << maxResult << '\n' << minResult << '\n';

    return 0;
}