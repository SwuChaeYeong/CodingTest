#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n, 0));

    // 현재 트리 간선
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u][v] = adj[v][u] = 1;
    }

    vector<pair<int,int>> ans;
    int R = 0;
    // 자기 자신과도 연결 처리
    for(int i = 0; i < n; i++){
        adj[i][i] = 1;
    }

    // 완전 그래프 여부 판단
    int maxEdgesPossible = 2 * (n - 1);
    int neededForComplete = (n * (n - 1)) / 2;
    if(maxEdgesPossible >= neededForComplete){
        // 완전 그래프 (지름=1)
        R = 1;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(!adj[i][j]){
                    ans.push_back({i+1, j+1});
                    adj[i][j] = adj[j][i] = 1;
                }
            }
        }
    }
    else{
        // 중심 노드에 모두 연결 (지름=2)
        R = 2;
        for(int i = 0; i < n; i++){
            if(!adj[i][0]){
                adj[i][0] = adj[0][i] = 1;
                ans.push_back({i+1, 1});
            }
        }
    }

    cout << ans.size() << "\n" << R << "\n";
    for(auto& p : ans){
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}