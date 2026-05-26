#include <string>
#include <math.h>

using namespace std;

int solution(int a, int b) {
    
    int answer = 0;
    
    // 둘 다 홀수
    if (a % 2 != 0 && b % 2 != 0)
    {
        answer = a * a + b * b;
    }
    // 둘 중 하나만 홀수
    else if (a % 2 != 0 || b % 2 != 0)
    {
        answer = 2 * (a + b);
    }
    else
    {
        answer = abs(a - b);
    }
    
    return answer;
}