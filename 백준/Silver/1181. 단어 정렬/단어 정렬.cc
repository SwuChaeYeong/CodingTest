#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    if (a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;

    string word[20000];

    for (int i = 0; i < size; i++)
    {
        cin >> word[i];
    }

    sort(word, word + size, compare);

    cout << word[0] << "\n";

    for (int i = 1; i < size; i++)
    {
        if (word[i] == word[i - 1])
            continue;

        cout << word[i] << "\n";
    }

    return 0;
}