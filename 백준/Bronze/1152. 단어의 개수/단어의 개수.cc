#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    int words = 0;
    int gap = true;

    getline(cin, str);

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ')
            gap = true;

        if (gap == true && str[i] != ' ') {
            ++words;
            gap = false;
        }
    }

    cout << words;

    return 0;
}