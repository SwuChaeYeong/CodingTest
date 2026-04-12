#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    
    vector<int> answer(52, 0);
    
    for (int i = 0; i < my_string.length(); i++)
    {
        if ('A' <= my_string[i] && my_string[i] <= 'Z')
            answer[my_string[i] - 65]++;
        
        else
            answer[my_string[i] - 71]++;
    }
    
    return answer;
}