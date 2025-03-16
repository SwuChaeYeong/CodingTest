#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word;
    cin >> word;

    string wordB = word;
    reverse(word.begin(), word.end());

    if (wordB.compare(word) == 0)
        cout << 1;
    else
        cout << 0;

    return 0;
}