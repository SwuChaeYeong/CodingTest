#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    
    int answer = 0;
    int a = 0;
    int b = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }
    
    while (pq.size() > 1 && pq.top() < K)
    {
        answer ++;
        
        a = pq.top();
        pq.pop();
        
        b = pq.top();
        pq.pop();
        
        pq.push(a + b * 2);
    }
    
    if (pq.top() < K)
        answer = -1;
    
    return answer;
}