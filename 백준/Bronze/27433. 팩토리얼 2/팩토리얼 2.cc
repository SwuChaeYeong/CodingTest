#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

long long factorial(int n)
{
    if (n <= 1)
        return 1;

    return n * factorial(n - 1);
}

int main()
{
    int num;
    cin >> num;

    long long result = factorial(num);

    cout << result;

    return 0;
}