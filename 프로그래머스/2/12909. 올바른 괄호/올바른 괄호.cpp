#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stack;
    
    for (char p : s)
    {
        // 여는 괄호면 스택에 삽입
        if (p == '(')
            stack.emplace(p);
        
        // 닫는 괄호
        else if (p == ')')
        {
            // 비어 있으면
            if (stack.empty())
                return false;
            
            else
                stack.pop();
        }
    }    

    return stack.empty();
}