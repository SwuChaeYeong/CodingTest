#include <string>
#include <vector>

using namespace std;

vector<int> solution(int money) {
    vector<int> answer;
    
    int americano = money / 5500;
    int remain = money - 5500 * americano;
    
    answer.push_back(americano);
    answer.push_back(remain);
    
    return answer;
}