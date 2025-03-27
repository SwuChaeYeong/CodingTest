#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int size;
    cin >> size;

    int num[1000];

    for (int i = 0; i < size; i++)
    {
        cin >> num[i];
    }

    sort(num, num + size);

    for (int i = 0; i < size; i++)
    {
        cout << num[i] << "\n";
    }

    return 0;
}