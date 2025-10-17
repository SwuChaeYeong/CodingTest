#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<int> lis;
    vector<int> index(N);

    for (int i = 0; i < N; i++)
    {
        // A[i]가 들어갈 위치를 lower_bound로 찾음
        auto it = lower_bound(lis.begin(), lis.end(), A[i]);
        int pos = it - lis.begin();

        if (it == lis.end())
            lis.push_back(A[i]);    // lis 길이 증가

        else
            *it = A[i];     // 기존 위치 값 갱신

        // lis의 몇 번째 위치에 들어갔는지 기록
        index[i] = pos;
    }

    // lis 길이
    int len = lis.size();
    cout << len << '\n';

    // 실제 lis 복원
    vector<int> res(len);
    int target = len - 1;

    // 경로 복원
    for (int i = N - 1; i >= 0; i--)
    {
        if (index[i] == target)
        {
            res[target] = A[i];
            target--;

            if (target < 0)
                break;
        }
    }

    for (int i = 0; i < len; i++)
        cout << res[i] << " ";

    return 0;
}