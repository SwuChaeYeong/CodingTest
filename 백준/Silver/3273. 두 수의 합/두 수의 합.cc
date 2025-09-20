#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n, x;
    // 배열 원소 개수
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // 합
    cin >> x;

    // 정렬
    sort(arr.begin(), arr.end());

    int left = 0, right = n - 1;
    int count = 0;

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == x)
        {
            count++;
            left++;
            right--;
        }
        else if (sum < x)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    cout << count;

    return 0;
}