#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    
    int answer = 0;
    
    while (true)
    {
        vector<int> prev = arr;
        
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] >= 50 && arr[i] % 2 == 0)
                arr[i] /= 2;

            else if (arr[i] < 50 && arr[i] % 2 != 0)
            {
                arr[i] *= 2;
                arr[i] += 1;
            }
        }
        
        if (prev == arr)
            break;
        
        answer++;
    }
    
    return answer;
}