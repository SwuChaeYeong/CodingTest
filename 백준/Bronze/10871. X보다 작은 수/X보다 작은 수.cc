#include <iostream>
using namespace std;

int main()
{
    int count;
    int max;
    int num[10000];

    cin >> count >> max;

    for (int i = 0; i < count; i++) {
        cin >> num[i];

        if (num[i] < max)
            cout << num[i] << " ";
    }

    return 0;
}