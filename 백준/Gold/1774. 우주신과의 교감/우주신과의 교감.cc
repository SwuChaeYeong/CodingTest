#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int N, M;
int parent[1001];
pair<int, int> pos[1001];
bool visited[1001];
double minDist[1001];

int findP(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = findP(parent[x]);
}

void unite(int a, int b)
{
    a = findP(a);
    b = findP(b);

    // 같은 집합이 아니면
    if (a != b)
        parent[b] = a;
}

// 거리
double distance(int a, int b)
{
    double dx = pos[a].first - pos[b].first;
    double dy = pos[a].second - pos[b].second;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> pos[i].first >> pos[i].second;

        // 초기화
        parent[i] = i;
        minDist[i] = 1e18;
    }

    // 이미 연결된 통로
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }


    // 1번 우주신을 시작점으로 설정
    int start = 1;
    for (int i = 1; i <= N; i++)
    {
        if (findP(i) == findP(start))
        {
            minDist[i] = 0;
        }
    }

    double answer = 0.0;

    for (int i = 0; i < N; i++)
    {
        int cur = -1;
        double best = 1e18;

        // 아직 방문 안 한 정점 중 최소 비용
        for (int j = 1; j <= N; j++)
        {
            if (!visited[j] && minDist[j] < best)
            {
                best = minDist[j];
                cur = j;
            }
        }

        // 방문 처리
        visited[cur] = true;
        answer += best;

        // 거리 갱신
        for (int next = 1; next <= N; next++)
        {
            if (!visited[next])
            {
                double d;
                
                if (findP(cur) == findP(next))
                    d = 0.0;

                else
                    d = distance(cur, next);

                minDist[next] = min(minDist[next], d);
            }
        }
    }

    printf("%.2f", answer);

    return 0;
}