#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string binomial) {
    
    int answer = 0;
    vector<string> temp;
    stringstream ss(binomial);
    string word;
    
    while (ss >> word)
    {
        temp.push_back(word);
    }
    
    if (temp[1] == "+")
        answer = stoi(temp[0]) + stoi(temp[2]);
        
    else if (temp[1] == "-")
        answer = stoi(temp[0]) - stoi(temp[2]);
            
    else if (temp[1] == "*")
        answer = stoi(temp[0]) * stoi(temp[2]);
    
    return answer;
}