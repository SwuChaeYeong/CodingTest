#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;

    int* num = (int*)malloc(sizeof(int) * size);

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