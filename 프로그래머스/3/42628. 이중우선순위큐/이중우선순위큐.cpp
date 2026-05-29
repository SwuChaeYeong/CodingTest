#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    
    vector<int> answer(2, 0);
    multiset<int> ms;
    
    for (const auto& s : operations)
    {
        int num = stoi(s.substr(2));
        
        // 숫자 삽입
        if (s[0] == 'I')
        {
            ms.insert(num);
        }
        // 숫자 삭제
        else
        {
            if (ms.empty())
                continue;
            
            // 최댓값 삭제
            if (num == 1)
            {
                auto iter = prev(ms.end());
                ms.erase(iter);
            }
            // 최솟값 삭제
            else
            {
                ms.erase(ms.begin());
            }
        }
    }
    
    if (!ms.empty())
    {
        answer[0] = *prev(ms.end());
        answer[1] = *ms.begin();
    }
    
    return answer;
}