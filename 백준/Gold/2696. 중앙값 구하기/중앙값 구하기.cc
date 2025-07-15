#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<>> minHeap;

        int M, x, cnt = 0;
        cin >> M;

        cout << (M + 1) / 2 << '\n';

        for (int i = 0; i < M; i++)
        {
            cin >> x;

            // 일단 최대 힙에 삽입
            if (maxHeap.empty() || x <= maxHeap.top())
                maxHeap.push(x);
            else
                minHeap.push(x);

            // 힙 크기 조절
            if (maxHeap.size() > minHeap.size() + 1)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else if (minHeap.size() > maxHeap.size())
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            if (i % 2 == 0)
            {
                cnt++;
                cout << maxHeap.top() << " ";

                if (cnt % 10 == 0)
                    cout << '\n';
            }         
        }
        cout << '\n';
    }
      
    return 0;
}