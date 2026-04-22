#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    int answer = 1;
    
    for (int i = 1; i < n; i++)
    {
        int sum = 0;
        int start = i;
        
        // 같거나 커지기 전까지 더함
        while (sum < n)
            sum += start++;
        
        if (sum == n)
            answer++;
    }
    
    return answer;
}