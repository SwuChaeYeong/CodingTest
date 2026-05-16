#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    
    if (arr1.size() > arr2.size())
    {
        return 1;
    }
    else if (arr1.size() < arr2.size())
    {
        return -1;
    }
    else
    {
        int sumA = 0, sumB = 0;
        for (int i = 0; i < arr1.size(); i++)
        {
            sumA += arr1[i];
            sumB += arr2[i];
        }
        
        if (sumA > sumB)
            return 1;
        
        else if (sumA < sumB)
            return -1;
        
        else
            return 0;
    }
}