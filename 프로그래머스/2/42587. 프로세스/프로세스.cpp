#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    
    int answer = 1;
    // 가장 큰 값이 top을 유지함 (우선순위 큐)
    priority_queue<int> pq;
    queue<pair<int, int>> q;
    
    for (int i = 0; i < priorities.size(); i++)
    {
        pq.push(priorities[i]);
        q.push({i, priorities[i]});
    }
    
    while (true)
    {
        pair<int, int> qf = q.front();
        q.pop();
        
        // 우선 순위가 가장 높은 것과 현재 pop한 우선순위가 같을 경우
        if(qf.second == pq.top())
        {
            // 찾고자하는 프로세스가 맞는 경우
            if (qf.first == location)
            {
                return answer;
            }
            // 아닌 경우 
            else
            {
                // 현재 진행된 거라 answer 올리고 pop
                pq.pop();
                answer++;
            }
        }
        else
        {
            // 다시 가장 마지막에 삽입
            q.push({qf.first, qf.second});
        }
    }
}