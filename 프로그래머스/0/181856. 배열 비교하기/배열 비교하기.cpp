#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    
    if (arr1.size() == arr2.size())
    {
        int sumA = 0;
        int sumB = 0;
        
        for (int i = 0; i < arr1.size(); i++)
        {
            sumA += arr1[i];
            sumB += arr2[i];
        }
        
        if (sumA == sumB)
            return 0;
        
        return (sumA < sumB) ? -1 : 1;
    }
    
    return (arr1.size() < arr2.size()) ? -1 : 1;
}