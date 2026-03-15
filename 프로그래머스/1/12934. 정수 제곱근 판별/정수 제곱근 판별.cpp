#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    
    long long answer = 0;
    
    // 제곱근 값을 정수로 변환
    long long a = sqrt(n);
    
    // 다시 제곱했을 때 n과 같은지
    if (a * a == n)
        answer = (a + 1) * (a + 1);
    
    else
        answer = -1;
    
    return answer;
}