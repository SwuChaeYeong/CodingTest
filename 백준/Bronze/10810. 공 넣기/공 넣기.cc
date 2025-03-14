#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int basket[100] = { 0 };

    int basketCount;
    int ballSize;

    cin >> basketCount >> ballSize;

    int startBasket, endBasket, ballNumber;

    for (int i = 0; i < ballSize; i++) {
        cin >> startBasket >> endBasket >> ballNumber;

        for (int j = startBasket; j <= endBasket; j++) {
            basket[j - 1] = ballNumber;
        }
    }
    
    for (int i = 0; i < basketCount; i++) {
        cout << basket[i] << " ";
    }

    return 0;
}