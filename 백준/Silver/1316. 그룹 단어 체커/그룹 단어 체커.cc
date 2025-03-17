#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size, count = 0;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        string str;
        cin >> str;

        bool isUsed[26];
        fill_n(isUsed, 26, false);
        bool isWord = true;

        isUsed[str[0] - 'a'] = true;

        for (int j = 1; j < str.length(); j++)
        {
            if (str[j] == str[j - 1])
                continue;

            if (isUsed[str[j] - 'a'])
                isWord = false;

            isUsed[str[j] - 'a'] = true;
        }

        if (isWord)
            count++;
    }

    cout << count;

    return 0;
}