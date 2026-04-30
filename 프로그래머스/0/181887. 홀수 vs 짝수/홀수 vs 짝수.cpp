#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> num_list) {
    
    int evenSum = 0;
    int oddSum = 0;
    
    for (int i = 0; i < num_list.size(); i++)
    {
        // 짝수
        if ((i + 1) % 2 == 0)
            evenSum += num_list[i];
        
        else
            oddSum += num_list[i];
    }
    
    return max(evenSum, oddSum);
}