#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    
    // 행 > 열 : 열 채워야 함
    if (arr.size() > arr[0].size())
    {
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i].resize(arr.size(), 0);
        }
    }
    // 열 > 행 : 행 채워야 함
    else if (arr.size() < arr[0].size())
    {
        arr.resize(arr[0].size(), vector<int>(arr[0].size(), 0));
    }
    
    return arr;    
}