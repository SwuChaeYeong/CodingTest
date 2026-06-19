#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>

using namespace std;

// 소수 찾기
bool isPrime(int n)
{
    if (n < 2)
        return false;
    
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    
    return true;
}

int solution(string numbers) {
    set<int> answer;
    
    sort (numbers.begin(), numbers.end());
    
    do 
    {
        string tmp;
        for (int i = 0; i< numbers.size(); i++)
        {
            tmp += numbers[i];
            // 소수면 삽입
            if (isPrime(stoi(tmp)))
                answer.insert(stoi(tmp));
        }
    } 
    while (next_permutation(numbers.begin(), numbers.end()));    
    
    return answer.size();
}