#include <string>
#include <vector>
#include <regex>
#include <sstream>

using namespace std;

vector<string> solution(string myStr) {
    
    vector<string> answer;
    // abc 중 하나를 공백으로 대체
    myStr = regex_replace(myStr, regex("[abc]"), " ");
    
    stringstream ss(myStr);
    string word;
    
    while (ss >> word)
        answer.push_back(word);
    
    if (answer.empty())
        answer.push_back("EMPTY");
    
    return answer;
}