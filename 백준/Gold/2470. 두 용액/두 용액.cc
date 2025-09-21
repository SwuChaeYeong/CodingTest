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

    vector<long long> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    // 정렬
    sort(arr.begin(), arr.end());

    int left = 0, right = N - 1;
    long long res = 2e9;
    long long resleft = 0, resright = 0;

    while (left < right)
    {
        long long sum = arr[left] + arr[right];

        if (abs(sum) < res)
        {
            res = abs(sum);
            resleft = arr[left];
            resright = arr[right];
        }

        if (sum == 0)
        {
            break;
        }
        else if (sum < 0)
        {
            left++;
        }
        else if (sum > 0)
        {
            right--;
        }
    }

    cout << resleft << " " << resright;

    return 0;
}