#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    int score[1000];

    int max = -1;

    cin >> size;

    for (int i = 0; i < size; i++) {
        cin >> score[i];

        if (max < score[i])
            max = score[i];
    }

    float sum = 0;

    for (int i = 0; i < size; i++) {
        sum += score[i] / (float)max * 100;
    }

    cout << sum / size;

    return 0;
}