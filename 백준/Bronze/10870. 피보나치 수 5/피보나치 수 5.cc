#include <iostream>
using namespace std;

long long fibonacci(int n)
{
    if (n <= 1)
        return n;

    if (n == 2)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int num;
    cin >> num;

    cout << fibonacci(num);

    return 0;
}