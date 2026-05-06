#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strArr) {
    
    for (int i = 0; i < strArr.size(); i++)
    {
        // 짝수
        if (i % 2 == 0)
            transform(strArr[i].begin(), strArr[i].end(), strArr[i].begin(), ::tolower);
        
        // 홀수
        else
            transform(strArr[i].begin(), strArr[i].end(), strArr[i].begin(), ::toupper);
    }
    
    return strArr;
}