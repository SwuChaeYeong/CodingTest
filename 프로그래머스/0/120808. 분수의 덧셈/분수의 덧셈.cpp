#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
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

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    
    vector<int> answer;
    
    int numerSum = numer1 * denom2 + numer2 * denom1;
    int denomSum = denom1 * denom2;
    
    int gcdNum = gcd(numerSum, denomSum);
    
    answer.push_back(numerSum / gcdNum);
    answer.push_back(denomSum / gcdNum);
        
    return answer;
}