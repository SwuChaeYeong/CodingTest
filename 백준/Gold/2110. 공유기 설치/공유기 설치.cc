#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N, C;
    cin >> N >> C;

    vector<int> homes(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> homes[i];
    }

    sort(homes.begin(), homes.end());

    // start는 1, end는 가장 큰 거리
    int start = 1, end = homes[N - 1] - homes[0];

    while (start <= end)
    {
        // 현재 거리
        int mid = (start + end) / 2;

        // 해당 거리가 되도록 설치할 수 있는지
        int count = 1;  // 첫 번째 집에 공유기 설치
        int lastPosition = homes[0];    // 첫 번째 집 위치

        for (int i = 1; i < N; i++)
        {
            if (homes[i] - lastPosition >= mid)
            {
                count++;
                lastPosition = homes[i];
            }
        }

        if (count >= C)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << end;
}