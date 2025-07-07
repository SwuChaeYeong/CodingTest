#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int K, N;
    cin >> K >> N;

    vector<int> lines(K);
    
    for (int i = 0; i < K; i++)
    {
        cin >> lines[i];
    }

    // 시작은 길이1, 마지막은 가장 긴 랜선의 길이
    long long start = 1, end = *max_element(lines.begin(), lines.end());

    while (start <= end)
    {
        // 현재 자른 랜선의 길이
        long long mid = (start + end) / 2;

        // 해당 길이로 몇 개 자를 수 있는지
        long long result = 0;

        for (int i = 0; i < K; i++)
        {
            result += lines[i] / mid;
        }

        // 해당 길이로 자를 수 있음
        if (result >= N)
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