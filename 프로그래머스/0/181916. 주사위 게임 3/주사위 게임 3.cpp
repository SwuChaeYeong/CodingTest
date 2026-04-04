#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int a, int b, int c, int d) {
    
    vector<int> list = { a, b, c, d };
    sort(list.begin(), list.end());
    
    // 전부 같은 경우
    if (list[0] == list[3])
    {
        return 1111 * list[0];
    }
    // 세 개 같은 경우
    else if (list[0] == list[2])
    {
        return pow(10 * list[0] + list[3], 2);
    }
    else if (list[1] == list[3])
    {
        return pow(10 * list[1] + list[0], 2);
    }
    // 두 개씩 같은 경우
    else if (list[0] == list[1] && list[2] == list[3])
        
    {
        return (list[0] + list[2]) * abs(list[0] - list[2]);
    }
    // 두 개만 같은 경우
    else if (list[0] == list[1] || list[1] == list[2] || list[2] == list[3])
    {
        if (list[0] == list[1])
        {
            return list[2] * list[3];
        }
        else if (list[1] == list[2])
        {
            return list[0] * list[3];
        }
        else
        {
            return list[0] * list[1];
        }
    }
    else
    {
        return list[0];
    }
}