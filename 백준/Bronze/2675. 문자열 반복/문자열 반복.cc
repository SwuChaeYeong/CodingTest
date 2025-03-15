#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int input;

    cin >> input;

    int repeat;
    char str[25];

    for (int i = 0; i < input; i++) {
        cin >> repeat >> str;

        for (int j = 0; j < 21; j++) {
            if (str[j] == NULL)
                break;

            for (int k = 0; k < repeat; k++) {
                cout << str[j];
            }
        }

        cout << "\n";
    }

    return 0;
}