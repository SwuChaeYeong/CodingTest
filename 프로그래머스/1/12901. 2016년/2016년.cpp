#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    
    vector<string> day = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    vector<int> month = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int n = 0;
    
    // 이전 달까지의 날짜를 더함
    for (int i = 0; i < a - 1; i++)
        n += month[i];
    
    // 현재 달 날짜
    n += b - 1;
    
    string answer = day[n % 7];
    return answer;
}