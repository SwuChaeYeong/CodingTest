#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    
    return a.second > b.second;
}

int solution(vector<int> array) {
    
    map<int, int> m;
    
    for (int n : array)
        m[n]++;
    
    vector<pair<int, int>> v(m.begin(), m.end());
    
    sort(v.begin(), v.end(), compare);
    
    if (v[0].second == v[1].second)
        return -1;
    
    return v[0].first;
}