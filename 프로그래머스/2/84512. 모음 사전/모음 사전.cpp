#include <string>
#include <vector>

using namespace std;

string word = "AEIOU";
string target;
int answer = 0;
int order = 0;

void dfs (string s)
{
    if (!s.empty())
    {
        order++;
        
        if (s == target)
        {
            answer = order;
            return;
        }
    }
    
    if (s.length() == 5)
        return;
    
    for (int i = 0; i < 5; i++)
    {
        dfs(s + word[i]);
    }
}

int solution(string word) {
    target = word;
    dfs("");
    return answer;
}