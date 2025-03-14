#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int basket[100];

    int basketCount;
    int ballSize;

    cin >> basketCount >> ballSize;

    for (int i = 0; i < basketCount; i++) {
        basket[i] = i + 1;
    }

    int basket1, basket2, temp;

    for (int i = 0; i < ballSize; i++) {

        cin >> basket1 >> basket2;

        temp = basket[basket1 - 1];
        basket[basket1 - 1] = basket[basket2 - 1];
        basket[basket2 - 1] = temp;
    }

    for (int i = 0; i < basketCount; i++) {
        cout << basket[i] << " ";
    }

    return 0;
}