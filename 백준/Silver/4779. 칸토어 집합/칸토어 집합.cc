#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void Cantor(string& str, int start, int length)
{
    if (length == 0)
        return;

    int lengthT = length / 3;
    int middle = start + lengthT;

    for (int i = middle; i < middle + lengthT; i++)
    {
        str[i] = ' ';
    }

    Cantor(str, start, lengthT);
    Cantor(str, middle + lengthT, lengthT);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n;
    string s;

    while (cin >> n)
    {
        n = pow(3, n);
        s.assign(n, '-');
        Cantor(s, 0, n);
        cout << s << "\n";
    }

    return 0;
}