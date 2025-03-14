#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num[9];

    int max = -1;
    int maxIndex = 0;

    for (int i = 0; i < 9; i++) {
        cin >> num[i];

        if (max < num[i]) {
            max = num[i];
            maxIndex = i;
        }
    }
    
    cout << max << "\n" << maxIndex + 1;

    return 0;
}