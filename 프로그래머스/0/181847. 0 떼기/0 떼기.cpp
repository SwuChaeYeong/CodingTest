#include <string>

using namespace std;

string solution(string n_str) {
    
    int idx = n_str.find_first_not_of('0');
    return n_str.substr(idx);
}