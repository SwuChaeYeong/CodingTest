#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;

    for (int i = 2; i <= num; i++)
    {
        while (num % i == 0)
        {
            cout << i << "\n";
            num /= i;
        }
    }

    return 0;
}