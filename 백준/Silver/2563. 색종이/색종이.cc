#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int array[101][101] = { 0 };

    int size;
    cin >> size;

    int count = 0;

    for (int i = 0; i < size; i++)
    {
        int x, y;
        cin >> x >> y;

        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                array[y + j][x + k]++;
            }
        }
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (array[i][j] > 0)
                count++;
        }
    }

    cout << count;

    return 0;
}