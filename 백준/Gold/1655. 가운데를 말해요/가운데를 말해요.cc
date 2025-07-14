#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;

    int N, x;
    cin >> N;

    for (int i = 0; i < N; i++)
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

        cout << maxHeap.top() << '\n';
    }
      
    return 0;
}