#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    
    //1단계 drops를 2차원 배열에 찍기 : O(m*n) (=drops.size())
    
    vector<vector<int>> board(m, vector<int>(n, 1e9));
    for(int i=0;i<drops.size(); ++i){
        int x = drops[i][0];
        int y = drops[i][1];
        board[x][y] = i+1;
    }
    
    //2단계 row (가로) 압축 O(M * N)
    vector<vector<int>> row_compression(m);
    
    for(int i=0; i<m; ++i){
        deque<int> deq;
        for(int j=0; j<n; ++j){
            if(j< w-1){
                while(!deq.empty()&&board[i][deq.back()]>= board[i][j]){
                    deq.pop_back();
                }
                deq.push_back(j);
            }else{
                if(!deq.empty()&& deq.front() <= j-w) deq.pop_front();
                while(!deq.empty()&&board[i][deq.back()]>=board[i][j]){
                    deq.pop_back();
                }
                deq.push_back(j);
                row_compression[i].push_back(board[i][deq.front()]);
            }
        }
    }
    
    
    //3단계 column 방향으로 압축 O(M*N)
    vector<vector<int>> col_compression(m - h + 1, vector<int>(n - w + 1));

    // 열(Column)의 개수는 n - w + 1 개!
    for(int i = 0; i < n - w + 1; ++i) { 
        deque<int> deq;
        for(int j = 0; j < m; ++j) {
            if(j < h - 1) {
                // 원본 board가 아니라, 2단계 결과물인 row_compression 참조!
                while(!deq.empty() && row_compression[deq.back()][i] >= row_compression[j][i]) {
                    deq.pop_back();
                }
                deq.push_back(j);
            } else {
                if(!deq.empty() && deq.front() <= j - h) deq.pop_front();
            
                // 여기서도 row_compression 참조!
                while(!deq.empty() && row_compression[deq.back()][i] >= row_compression[j][i]) {
                    deq.pop_back();
                }
                deq.push_back(j);
            
                // j는 윈도우의 끝 인덱스이므로, 저장할 때는 j - h + 1 로 인덱싱 매핑
                col_compression[j - h + 1][i] = row_compression[deq.front()][i];
            }
        }
    }
    
    int max_val = 0;
    int max_r = 0;
    int max_c = 0;
    
    for(int i=0; i<col_compression.size();++i){
        for(int j=0; j<col_compression[0].size();++j){
            if(col_compression[i][j]==0) return {i,j};
            if(max_val < col_compression[i][j]) {
                max_val = col_compression[i][j];
                max_r = i;
                max_c = j;
            }
        }
    }
    return {max_r, max_c};
}