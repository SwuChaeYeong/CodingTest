#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    vector<int> weight = {781, 156, 31, 6, 1};
    int answer = 0;
    
    for (int i = 0; i < word.size(); i++)
    {
        int idx;
        
        if (word[i] == 'A')
            idx = 0;
        
        else if (word[i] == 'E')
            idx = 1;
        
        else if (word[i] == 'I')
            idx = 2;
        
        else if (word[i] == 'O')
            idx = 3;
        
        else
            idx = 4;
        
        answer += idx * weight[i] + 1;
    }
    
    return answer;
}