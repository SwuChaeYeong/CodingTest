#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size, des;
    int num[100];

    cin >> size >> des;

    int min = des, result = 0;

    for (int i = 0; i < size; i++)
    {
        cin >> num[i];
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                if (des - (num[i] + num[j] + num[k]) == 0)
                {
                    result = des;
                    goto jump;
                }
                else if (des - (num[i] + num[j] + num[k]) < 0)
                {
                    continue;
                }
                else if (des - (num[i] + num[j] + num[k]) < min)
                {
                    min = abs(des - (num[i] + num[j] + num[k]));
                    result = num[i] + num[j] + num[k];
                }
            }
        }
    }

    jump:
    cout << result;

    return 0;
}