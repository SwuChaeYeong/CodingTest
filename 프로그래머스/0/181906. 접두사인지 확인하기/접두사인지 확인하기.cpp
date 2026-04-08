#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
    
    int answer = 0;
    
    if (is_prefix == my_string.substr(0, is_prefix.length()))
        answer = 1;
    
    return answer;
}