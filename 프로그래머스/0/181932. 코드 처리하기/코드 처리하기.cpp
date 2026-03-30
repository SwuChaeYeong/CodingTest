#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    
    string answer = "";
    bool mode = false;
    
    for (int i = 0; i < code.length(); i++)
    {
        // code가 "1"이면 모드를 바꿈
        if (code[i] == '1')
        {
            mode = !mode;
            continue;
        }
        
        // mode가 0(false)
        if (!mode)
        {
            // idx가 짝수일 때만
            if (i % 2 == 0)
                answer += code[i];
        }
        else
        {
            // idx가 홀수일 때만
            if (i % 2 != 0)
                answer += code[i];
        }
    }
    
    if (answer == "")
        answer = "EMPTY";
    
    return answer;
}