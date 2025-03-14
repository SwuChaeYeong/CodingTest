#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int basket[100];

    int basketCount;
    int switchSize;

    cin >> basketCount >> switchSize;

    for (int i = 0; i < basketCount; i++) {
        basket[i] = i + 1;
    }

    int basket1, basket2, temp;

    for (int i = 0; i < switchSize; i++) {

        cin >> basket1 >> basket2;

        reverse(basket + basket1 - 1, basket + basket2);
    }

    for (int i = 0; i < basketCount; i++) {
        cout << basket[i] << " ";
    }

    return 0;
}