#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
// 맵 입력
vector<string> map;

// 각 정점 방문 순서 저장
bool visited[25][25];
int houseCount;

// 상하좌우 방향
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void DFS(int x, int y)
{
    // 방문 처리
    visited[x][y] = true;
    // 단지 크기 증가
    houseCount++;

    // 인접 노드 체크 (상하좌우)
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 맵 범위를 벗어나지 않는지 체크
        if (nx >= 0 && nx < N && ny >= 0 && ny < N)
        {
            if (map[nx][ny] == '1' && !visited[nx][ny])
                DFS(nx, ny);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    cin >> N;
    map.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> map[i];
    }

    vector<int> sizes;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // 단지가 있고, 방문하지 않은 경우 (시작 노드)
            if (map[i][j] == '1' && !visited[i][j])
            {
                houseCount = 0;
                DFS(i, j);
                sizes.push_back(houseCount);
            }
        }
    }

    // 단지 정렬
    sort(sizes.begin(), sizes.end());
    // 단지 개수 출력
    cout << sizes.size() << '\n';
    // 단지 크기 출력
    for (int size : sizes)
    {
        cout << size << '\n';
    }
      
    return 0;
}