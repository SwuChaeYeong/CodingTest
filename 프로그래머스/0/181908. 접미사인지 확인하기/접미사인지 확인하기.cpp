#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
    
    int answer = 0;
    int len = my_string.size() - is_suffix.size();
    
    if (len >= 0)
    {
        if (my_string.substr(len) == is_suffix)
            answer = 1;
    }
    return answer;
}