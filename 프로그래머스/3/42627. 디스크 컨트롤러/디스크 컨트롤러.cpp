#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const vector<int> &a, const vector<int> &b)
{
    if (a[1] == b[1])
        return a[0] <= b[0];
    
    return a[1] <= b[1];
}

int solution(vector<vector<int>> jobs) {
    
    int answer = 0;
    int timer = 0;
    int cnt = jobs.size();
    
    sort(jobs.begin(), jobs.end(), compare);
    
    while (!jobs.empty())
    {
        for (int i = 0; i < jobs.size(); i++)
        {
            // 들어온 타임이 현재 타임보다 작을 경우 작업 가능
            if (jobs[i][0] <= timer)
            {
                timer += jobs[i][1];
                // 요청 시점부터 종료까지 걸리는 시간을 더해줌
                answer += timer - jobs[i][0];
                // 대기 큐에서 제거
                jobs.erase(jobs.begin() + i);
                break;
            }
            
            if (i == jobs.size() - 1)
                timer++;
        }
    }
    
    return answer / cnt;
}