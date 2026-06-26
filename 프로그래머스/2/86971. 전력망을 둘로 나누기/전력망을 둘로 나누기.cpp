#include <string>
#include <vector>

using namespace std;

vector<int> graph[101];
bool visited[101];

int dfs (int now, int a, int b)
{
    visited[now] = true;
    int cnt = 1; 
    
    for (int next : graph[now])
    {
        // 끊은 간선이면 건너뛰기
        if ((now == a && next == b) || (now == b && next == a))
            continue;
        
        if (!visited[next])
            cnt += dfs(next, a, b);
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    for (auto &wire : wires)
    {
        int u = wire[0];
        int v = wire[1];
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    for (auto &wire : wires)
    {
        fill(visited, visited + 101, false);
        
        int a = wire[0];
        int b = wire[1];
        
        int cnt = dfs(a, a, b);
        
        answer = min(answer, abs(cnt - (n - cnt)));
    }
    
    return answer;
}