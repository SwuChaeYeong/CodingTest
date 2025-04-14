#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;

    int num[50];

    for (int i = 0; i < size; i++)
    {
        cin >> num[i];
    }

    sort(num, num + size);

    cout << num[0] * num[size - 1];

    return 0;
}