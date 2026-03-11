#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    
    int sum = 0;
    int n = x;
    
    // 자릿수 합
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    
    // 하샤드 수 판별
    if (x % sum != 0)
        answer = false;
        
    return answer;
}