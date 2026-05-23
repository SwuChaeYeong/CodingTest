#include <string>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    
    int total = m * n;
    vector<int> rain(total, INT_MAX);
    
    // 2차원 배열을 1차원 배열로
    for (int i = 0; i < drops.size(); i++)
    {
        int r = drops[i][0];
        int c = drops[i][1];
        
        // 비 오는 순서를 저장
        rain[r * n + c] = i + 1;
    }
    
    int newN = n - w + 1;
    vector<int> rowMin(m * newN);
    
    for (int r = 0; r < m; r++)
    {
        deque<int> dq;
        
        for (int c = 0; c < n; c++)
        {
            while (!dq.empty() && rain[r * n + dq.back()] >= rain[r * n + c])
            {
                dq.pop_back();
            }
            
            dq.push_back(c);
            
            if (dq.front() <= c - w)
                dq.pop_front();
            
            if (c >= w - 1)
            {
                rowMin[r * newN + (c - w + 1)] = rain[r * n + dq.front()];
            }
        }
    }
    
    int newM = m - h + 1;
    
    int bestTime = -1;
    int bestR = 0;
    int bestC = 0;
    
    for (int c = 0; c < newN; c++)
    {
        deque<int> dq;
        
        for (int r = 0; r < m; r++)
        {
            int val = rowMin[r * newN + c];
            
            while (!dq.empty() && rowMin[dq.back() * newN + c] >= val)
                dq.pop_back();
            
            dq.push_back(r);
            
            if (dq.front() <= r - h)
                dq.pop_front();
            
            if (r >= h - 1)
            {
                int cur = rowMin[dq.front() * newN + c];
                int sr = r - h + 1;
                
                if (cur > bestTime || (cur == bestTime && (sr < bestR || (sr == bestR && c < bestC))))
                    {
                        bestTime = cur;
                        bestR = sr;
                        bestC = c;
                    }
            }
        }
    }
    
    return {bestR, bestC};
}