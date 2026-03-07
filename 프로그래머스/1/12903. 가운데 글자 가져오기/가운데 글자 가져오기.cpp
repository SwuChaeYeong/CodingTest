#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    
    // 문자열 길이
    int n = s.length();
    
    // 문자열 길이가 짝수
    if (n % 2 == 0)
        return s.substr(n/2 - 1, 2);
    
    // 문자열 길이가 홀수
    else
        return s.substr(n/2, 1);
}