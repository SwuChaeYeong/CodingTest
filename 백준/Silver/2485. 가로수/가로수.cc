#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int Gcd(int a, int b)
{
    int remain = a % b;

    if (remain == 0)
        return b;
    else
        return Gcd(b, remain);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;
    
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + size);

    int gcd = Gcd(arr[1] - arr[0], arr[2] - arr[1]);
    for (int i = 3; i < size; i++)
    {
        gcd = Gcd(gcd, arr[i] - arr[i - 1]);
    }

    int result = 0;
    for (int i = 1; i < size; i++)
    {
        result += (arr[i] - arr[i - 1]) / gcd - 1;
    }

    cout << result;

    return 0;
}