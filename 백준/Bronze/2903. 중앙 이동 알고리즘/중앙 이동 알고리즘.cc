#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;

    int result = 2;

    for (int i = 0; i < num; i++)
    {
        result += pow(2, i);
    }
    
    cout << result * result;

    return 0;
}