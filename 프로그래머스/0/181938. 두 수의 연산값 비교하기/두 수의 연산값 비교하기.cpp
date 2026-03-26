#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    
    string s = to_string(a) + to_string(b);
    int n = 2 * a * b;
    
    if (n >= stoi(s))
        return n;
    
    else
        return stoi(s);
}