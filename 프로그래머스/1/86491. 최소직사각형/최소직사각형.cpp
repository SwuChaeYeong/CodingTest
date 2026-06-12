#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    
    int w = 0;
    int h = 0;
    
    for (int i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] < sizes[i][1])
        {
            int tmp = sizes[i][1];
            sizes[i][1] = sizes[i][0];
            sizes[i][0] = tmp;
        }
        
        w = max(w, sizes[i][0]);
        h = max(h, sizes[i][1]);

    }
    
    return w * h;
    
}