#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    int money;
    int quot[4] = { 25, 10, 5, 1 };
    int q, d, n, p;

    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cin >> money;
        
        for (int i = 0; i < 4; i++)
        {
            cout << money / quot[i] << " ";
            money %= quot[i];
        }

        cout << "\n";
    }
    

    return 0;
}