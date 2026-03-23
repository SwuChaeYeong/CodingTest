#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    
    int answer = 0;
    
    // p의 길이
    int pL = p.length();
    // p를 숫자로 변환
    long long pN = stoll(p);
    
    for (int i = 0; i < t.length() - pL + 1; i++)
    {
        long long tN = stoll(t.substr(i, pL));
        
        if (tN <= pN)
            answer++;
    }
    
    return answer;
}