#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    
    int answer = 1;    
    unordered_map<string, int> map;
    
    for(const auto& c : clothes)
    {
        map[c[1]]++;
    }
    
    for (const auto& item : map)
    {
        answer *= (item.second + 1);
    }
    
    return answer - 1;
    
    return answer;
}