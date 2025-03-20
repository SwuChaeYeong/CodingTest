#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int repeat;
    cin >> repeat;

    int result = 0;

    for (int i = 0; i < repeat; i++)
    {
        int num;
        cin >> num;

        int countD = 0;

        for (int j = 1; j <= num; j++)
        {
            if (num % j == 0)
                countD++;
        }

        if (countD == 2)
            result++;
    }

    cout << result;

    return 0;
}