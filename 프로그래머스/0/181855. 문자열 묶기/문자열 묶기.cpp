#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> strArr) {
    
    int counts[31] = {0}; 
    
    for (int i = 0; i < strArr.size(); i++)
    {
        counts[strArr[i].size()]++;
    }
    
    int answer = 0;
    
    for (int i = 0; i < 31; i++)
    {
        answer = max(answer, counts[i]);
    }
    
    return answer;
}