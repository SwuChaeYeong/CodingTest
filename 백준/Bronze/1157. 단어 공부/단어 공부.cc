#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int alpha[26];
    fill_n(alpha, 26, 0);

    string word;
    cin >> word;

    int max = -1;
    char result = 0;

    for (int i = 0; i < word.size(); i++) {
        //대문자
        if (word[i] >= 65 && word[i] <= 90) {
            for (int j = 0; j < 26; j++) {
                if (word[i] == 65 + j)
                    alpha[j]++;
            }
        }
        //소문자
        if (word[i] >= 97 && word[i] <= 122) {
            for (int j = 0 ; j < 26; j++)
            {
                if (word[i] == 97 + j)
                    alpha[j]++;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (alpha[i] > max) {
            result = i + 65;
            max = alpha[i];
        }
        else if (alpha[i] != 0 && alpha[i] == max) {
            result = '?';
        }
    }

    cout << result;

    return 0;
}