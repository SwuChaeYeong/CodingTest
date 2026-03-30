#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    
    int last = num_list[num_list.size() - 1];
    int lastE = num_list[num_list.size() - 2];
    
    if (last > lastE)
    {
        num_list.push_back(last - lastE);
    }
    else
    {
        num_list.push_back(last * 2);
    }
    
    return num_list;
}