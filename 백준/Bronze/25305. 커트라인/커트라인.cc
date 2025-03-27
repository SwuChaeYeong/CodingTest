#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int num[1000];
    int student;
    int top;

    cin >> student >> top;

    for (int i = 0; i < student; i++)
    {
        cin >> num[i];
    }

    sort(num, num + student, greater<int>());

    cout << num[top - 1];

    return 0;
}