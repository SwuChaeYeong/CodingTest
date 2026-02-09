#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N;
    cin >> N;

    vector<int> result;

    // 홀수 오름차순
    for (int i = 1; i <= N; i += 2)
    {
        result.push_back(i);
    }

    // 짝수 내림차순
    for (int i = (N % 2 == 0 ? N : N - 1); i >= 2; i -= 2)
    {
        result.push_back(i);
    }

    for (int x : result)
    {
        cout << x << ' ';
    }

    return 0;
}