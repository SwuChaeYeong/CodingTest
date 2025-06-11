#include <iostream>
#include <vector>
#include <string>
using namespace std;

int psum[26][200000] = { 0 };

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    string str;
    cin >> str;

    int n;
    cin >> n;

    for (int i = 0; i < 26; i++)
    {
        for (int j = 1; j <= str.length(); j++)
        {
            if (str[j - 1] - 97 == i)
                psum[i][j] = psum[i][j - 1] + 1;
            else
                psum[i][j] = psum[i][j - 1];
        }
    }

    char a;
    int l, r;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> l >> r;
        cout << psum[a - 97][r + 1] - psum[a - 97][l] << '\n';
    }

    return 0;
}