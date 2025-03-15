#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    string str;

    int sum = 0;

    cin >> size;
    cin >> str;

    for (int i = 0; i < size; i++)
    {
        sum += (str[i] - '0');
    }

    cout << sum;
}