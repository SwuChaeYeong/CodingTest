#include <string>
#include <vector>

using namespace std;

int gcd (int a, int b)
{
    while (b != 0) 
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    
    return a;
}

int solution(int n) {
    return n / gcd(n, 6);
}