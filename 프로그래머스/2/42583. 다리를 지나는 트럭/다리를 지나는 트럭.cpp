#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
    int answer = 0;
    queue<int> q;
    int weightSum = 0;
    int i = 0;
    
    while(1)
    {
        int curWeight = truck_weights[i];
        
        // 마지막 값만 남은 경우
        if (i == truck_weights.size())
        {
            answer += bridge_length;
            break;
        }
        
        // 자동차 무게가 견딜 수 있는 무게보다 작으면
        if (weightSum + curWeight <= weight)
        {
            weightSum += curWeight;
            q.push(curWeight);
            i++;
        }
        else
        {
            // 시간 초 계산
            q.push(0);
        }
        
        // 차가 다리를 다 건넜을 경우
        if (q.size() == bridge_length)
        {
            // 나간 다리 무게에서 제외
            weightSum -= q.front();
            q.pop();
        }
        
        answer++;
    }
    
    return answer;
}