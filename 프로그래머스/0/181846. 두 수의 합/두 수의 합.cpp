#include <string>
#include <algorithm>

using namespace std;

string solution(string a, string b) {
    
    string answer = "";
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    // 길이 맞춰서 0만큼 채움
    if (a.length() < b.length())
        a.resize(b.size(), '0');
    
    else
        b.resize(a.size(), '0');
    
    // 더해서 10 넘는 올림수
    int carry = 0;
    
    for (int i = 0; i < a.size(); i++)
    {
        int temp = (a[i] - '0') + (b[i] - '0') + carry;
        answer += (temp % 10) + '0';
        carry = temp / 10;
    }
    
    // 마지막 carry 처리
    if (carry)
        answer += carry + '0';
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}