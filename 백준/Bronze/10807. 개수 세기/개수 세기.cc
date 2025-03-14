#include <iostream>
using namespace std;

int main()
{
    int count;
    int num[100];
    int same;
    int result = 0;

    cin >> count;

    for (int i = 0; i < count; i++) {
        cin >> num[i];
    }

    cin >> same;

    for (int i = 0; i < count; i++) {
        if (num[i] == same)
            result++;
    }

    cout << result;

    return 0;
}