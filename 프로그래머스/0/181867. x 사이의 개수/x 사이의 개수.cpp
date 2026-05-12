#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(string myString) {
    
    vector<int> answer;
    stringstream ss(myString);
    string word;
    
    while (getline(ss, word, 'x'))
    {
        answer.push_back(word.length());
    }
    
    if (myString.back() == 'x')
    {
        answer.push_back(0);
    }
    
    return answer;
}