#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N;
    cin >> N;

    int L = 1, R = N;
    vector<int> ans;
    ans.reserve(N);

    while (L < R)
    {
        ans.push_back(L++);
        ans.push_back(R--);
    }

    if (L == R)
        ans.push_back(L);

    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << (i + 1 < N ? ' ' : '\n');
    }

    return 0;
}