#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N, S;
    cin >> N >> S;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int start = 0, end = 0;
    long long sum = 0;
    int ans = N + 1;    // 길이

    while (true)
    {
        // 만약 원하는 S값보다 크면
        if (sum >= S)
        {
            // 길이가 더 짧으면 갱신
            ans = min(ans, end - start);

            // 합에서 현재 start 부분 빼고 start 증가
            sum -= arr[start++];
        }
        else if (end == N)
        {
            break;
        }
        else
        {
            sum += arr[end++];
        }
    }

    if (ans == N + 1) cout << 0;
    else cout << ans;

    return 0;
}