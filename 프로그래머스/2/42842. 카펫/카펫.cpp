#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    
    int len = brown / 2 + 2;
    int h = 3;
    int w = len - 3;
    
    while (w >= h)
    {
        if (w * h == (brown + yellow))
            break;
        
        w--;
        h++;
    }
    
    return {w, h};
}