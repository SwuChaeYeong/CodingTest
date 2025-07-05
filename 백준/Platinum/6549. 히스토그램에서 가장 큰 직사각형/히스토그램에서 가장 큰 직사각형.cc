#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {

        // 입력
        int n;
        cin >> n;

        // 0 입력 받으면 종료
        if (n == 0)
            return 0;

        // 히스토그램 입력
        vector<long long> heights(n + 1); // 끝에 0 추가할 거라 n+1
        for (int i = 0; i < n; i++) 
        {
            cin >> heights[i];
        }
        heights[n] = 0; // 마지막에 0 추가

        stack<int> s;   // 스택
        long long maxArea = 0;  // 최대 넓이

        // 넓이 계산
        for (int i = 0; i <= n; i++) {
            // heights[i]가 스택의 top보다 작으면
            while (!s.empty() && heights[s.top()] > heights[i]) 
            {
                // 지금까지의 직사각형 높이로는 현재까지 확장할 수 있으므로
                // 넓이 계산 시작

                // 꺼낸 막대의 인덱스
                int topIndex = s.top();
                s.pop();

                // 꺼낸 막대의 높이
                long long height = heights[topIndex];
                long long width;

                // 너비 계산
                if (s.empty()) {
                    // 스택이 비었다면 현재까지 높은 게 하나도 없으므로
                    width = i;
                }
                else {
                    width = i - s.top() - 1;
                }

                long long area = height * width;
                if (area > maxArea) 
                    maxArea = area;
            }
            s.push(i);
        }

        cout << maxArea << '\n';
    }

    return 0;
}