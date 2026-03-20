#include <string>
#include <vector>

using namespace std;

int gcd (int a, int b)
{
    int c;
    
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    
    return a;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    answer.push_back(gcd(n, m));
    answer.push_back(n * m / gcd(n, m));
    
    return answer;
}