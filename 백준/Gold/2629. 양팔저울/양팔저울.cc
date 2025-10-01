#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 추는 최대 500g, 30개니까 최대 무게 차이는 15000
const int MAX_WEIGHT = 15000;
// i번째 추까지 고려했을 때 w를 만들 수 있는지
bool dp[31][MAX_WEIGHT + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    // 추 입력
    int N;
    cin >> N;

    vector<int> weight(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> weight[i];
    }

    // 초기 상태 (추를 하나도 안 씀)
    dp[0][0] = true;

    for (int i = 1; i <= N; i++)
    {
        // i번째 추 무게
        int w = weight[i - 1];

        for (int diff = 0; diff <= MAX_WEIGHT; diff++)
        {
            // 이전 저울의 상태가 만들어낼 수 있는 무게 차이인 경우
            if (dp[i - 1][diff])
            {
                // 1. 추를 사용하지 않음
                // 이번 추를 사용하지 않는 경우
                // 이전 저울의 상태와 무게 차이가 동일함
                dp[i][diff] = true;

                // 2. 추를 같은 쪽에 올림
                // 이번 추를 사용해 같은 쪽에 올리면 새 차이는 diff + w
                if (diff + w <= MAX_WEIGHT)
                    dp[i][diff + w] = true;

                // 3. 추를 반대쪽에 올림
                // 이번 추를 사용해 반대쪽에 올리면 새 차이는 | diff - w |
                if (abs(diff - w) <= MAX_WEIGHT)
                    dp[i][abs(diff - w)] = true;
            }
        }
    }


    // 구슬 입력
    int M;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int bead;
        cin >> bead;

        if (bead > MAX_WEIGHT)
            cout << "N ";

        else if (dp[N][bead])
            cout << "Y ";

        else
            cout << "N ";
    }
    
    return 0;
}