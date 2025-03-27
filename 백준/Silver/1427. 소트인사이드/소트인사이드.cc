#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string stringNum;
    cin >> stringNum;

    int* num = (int*)malloc(sizeof(int) * stringNum.size());

    for (int i = 0; i < stringNum.size(); i++)
    {
        num[i] = stringNum[i] - '0';
    }

    sort(num, num + stringNum.size(), greater<int>());

    for (int i = 0; i < stringNum.size(); i++)
    {
        cout << num[i];
    }

    return 0;
}