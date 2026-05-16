#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    
    int size = 1;    
    while (size < arr.size())
    {
        size *= 2;
    }
    
    arr.resize(size, 0);
    
    return arr;
}