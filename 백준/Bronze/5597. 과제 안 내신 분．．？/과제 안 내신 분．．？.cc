#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool student[30] = { false };

    int fin;

    for (int i = 0; i < 28; i++) {
        cin >> fin;
        student[fin - 1] = true;
    }

    for (int i = 0; i < 30; i++) {
        if (!student[i])
            cout << i + 1 << "\n";
    }

    return 0;
}