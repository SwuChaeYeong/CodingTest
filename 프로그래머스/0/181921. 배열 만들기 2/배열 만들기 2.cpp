#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    
    vector<int> answer;
    
    for (int i = l; i <= r; i++)
    {
        string tmp = to_string(i);
        bool isIncluded = true;
        
        for (char c : tmp)
        {
            // 0과 5 둘 다 아니면
            if (c != '0' && c != '5')
            {
                // 벡터에 포함 X
                isIncluded = false;
                break;
            }
        }
        
        if (isIncluded)
            answer.push_back(i);
    }
    
    // 비어있으면
    if (answer.empty())
        answer.push_back(-1);
    
    return answer;
}