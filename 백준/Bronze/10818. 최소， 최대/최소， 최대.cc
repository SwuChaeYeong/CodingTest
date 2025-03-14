#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;

    int* num = (int*)malloc(sizeof(int) * size);

    int min = 1000000;
    int max = -1000000;

    for (int i = 0; i < size; i++) {
        cin >> num[i];

        if (num[i] > max)
            max = num[i];

        if (num[i] < min)
            min = num[i];
    }

    cout << min << " " << max;

    return 0;
}