#include <iostream>
#include <cstring>
using namespace std;

int cnt = 0;

int isPalindrome(const char* s, int l, int r) {

    cnt++;

    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return isPalindrome(s, l + 1, r - 1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;

    while (size--)
    {
        cnt = 0;

        char word[1001];
        cin >> word;

        cout << isPalindrome(word, 0, strlen(word) - 1) << " " << cnt << "\n";
    }
}