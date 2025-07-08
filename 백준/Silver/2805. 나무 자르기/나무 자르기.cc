#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> trees(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> trees[i];
    }

    // 시작은 높이 1, 마지막은 가장 높이가 높은 나무-1
    int start = 1, end = *max_element(trees.begin(), trees.end());

    while (start <= end)
    {
        // 현재 절단기의 높이
        long long mid = (start + end) / 2;

        // 해당 길이로 몇 개 자를 수 있는지
        long long result = 0;

        for (int i = 0; i < N; i++)
        {
            if (trees[i] > mid)
                result += trees[i] - mid;
        }

        if (result >= M)
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