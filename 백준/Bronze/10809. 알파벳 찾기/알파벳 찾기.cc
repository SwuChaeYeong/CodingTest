#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int alpha[26];
    fill_n(alpha, 26, -1);

    char str[101];
    cin >> str;

    for (int i = 0; i < 100; i++) {
        if (str[i] == NULL)
            break;

        for (int j = 0; j < 26; j++) {
            if (str[i] == j + 97) {
                if (alpha[j] != -1)
                    break;

                alpha[j] = i;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        cout << alpha[i] << " ";
    }
}