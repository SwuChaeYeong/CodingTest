#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N, K;
    cin >> N >> K;

    // 보석. 무게, 가치 순서로 입력
    vector<pair<int, int>> jewels(N);
    for (int i = 0; i < N; i++)
    {
        cin >> jewels[i].first >> jewels[i].second;
    }

    // 가방
    vector<int> bags(K);
    for (int i = 0; i < K; i++)
    {
        cin >> bags[i];
    }

    // 보석을 무게 기준으로 오름차순 정렬
    sort(jewels.begin(), jewels.end());
    // 가방을 무게 기준으로 오름차순 정렬
    sort(bags.begin(), bags.end());

    priority_queue<int> pq;

    long long total = 0;
    int j = 0;

    // 가방 하나씩 확인
    for (int i = 0; i < K; i++)
    {
        // 현재 가방에 담을 수 있는 보석을 모두 pq에 넣음
        // j가 더해진 상태로 유지되기 때문에 중복 X
        while (j < N && jewels[j].first <= bags[i])
        {
            pq.push(jewels[j].second);
            ++j;
        }

        // 가치가 가장 높은 보석 선택
        if (!pq.empty())
        {
            total += pq.top();
            pq.pop();
        }
    }

    cout << total;
      
    return 0;
}