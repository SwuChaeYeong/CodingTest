#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
bool visited[8] = {0};

void dfs(int cnt, int k, vector<vector<int>> &dungeons)
{
    // 더 크면 갱신
    answer = max(answer, cnt);
    
    for (int i = 0; i < dungeons.size(); i++)
    {
        // 방문하지 않았고, 방문할 수 있는 피로도면
        if (!visited[i] && dungeons[i][0] <= k)
        {
            // 방문 표시
            visited[i] = true;
            // 갱신
            dfs(cnt + 1, k - dungeons[i][1], dungeons);
            
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(0, k, dungeons);
    return answer;
}