#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    
    vector<vector<int>> answer(n, vector<int> (n, 0));
    
    int num = 1;
    
    int startCol = 0;
    int endCol = n - 1;
    int startRow = 0;
    int endRow = n - 1;
    
    while (num <= n * n)
    {
        // 왼 > 오
        for (int i = startCol; i <= endCol; i++)
        {
            answer[startRow][i] = num++;
        }
        // 왼 > 오로 가는 1줄 채워졌으므로 startRow 증가
        startRow++;
        
        // 오른쪽 위 > 아래
        for (int i = startRow; i <= endRow; i++)
        {
            answer[i][endCol] = num++;
        }
        // 오른쪽 위 > 아래로 가는 1줄 채워졌으므로 endCol 감소
        endCol--;
        
        // 오른쪽 아래 > 왼쪽
        for (int i = endCol; i >= startCol; i--)
        {
            answer[endRow][i] = num++;
        }
        // 오른쪽 아래 > 왼쪽 가는 1줄 채워졌으므로 endRow 감소
        endRow--;
        
        // 왼쪽 아래 > 위
        for (int i = endRow; i >= startRow; i--)
        {
            answer[i][startCol] = num++;
        }
        // 왼쪽 아래 > 위쪽 가는 1줄 채워졌으므로 startCol 증가
        startCol++;
    }
    
    return answer;
}