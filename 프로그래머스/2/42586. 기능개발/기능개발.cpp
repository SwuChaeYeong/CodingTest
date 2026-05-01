#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    vector<int> answer;
    queue<int> q;
    
    for (int i = 0; i < progresses.size(); i++)
    {
        // 배포까지 걸리는 시간 (숫자 올림을 위해서 +b - 1)
        int days = (100 - progresses[i] + speeds[i] - 1) / speeds[i];
        
        // 비어있지 않고, 앞에 들어간 시간이 지금보다 작을 때
        if (!q.empty() && q.front() < days)
        {
            // 현재까지 배포 가능한 것들 배포
            answer.push_back(q.size());
            
            // 다시 전부 비우기
            while (!q.empty())
                q.pop();
        }
        
        q.push(days);
    }
    
    answer.push_back(q.size());
    
    return answer;
}