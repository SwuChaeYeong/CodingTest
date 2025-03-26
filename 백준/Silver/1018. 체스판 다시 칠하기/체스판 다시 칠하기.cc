#include <iostream>
#include <string>

using namespace std;

int main()
{
    string arr[50];
    int row, column, count = 65;

    cin >> row >> column;

    for (int i = 0; i < row; i++)
    {
        cin >> arr[i];
    }

    int temp1, temp2;

    for (int x = 0; x < row - 7; x++)
    {
        for (int y = 0; y < column - 7; y++)
        {
            //첫째 칸이 W인 경우
            for (int i = x; i < x + 8; i++)
            {
                for (int j = y; j < y + 8; j++)
                {
                    if ((i - x + j - y) % 2 == 0)
                    {
                        if (arr[i][j] != 'W')
                            temp1++;
                    }
                    else
                    {
                        if (arr[i][j] != 'B')
                            temp1++;
                    }
                }
            }

            //첫째 칸이 B인 경우
            for (int i = x; i < x + 8; i++)
            {
                for (int j = y; j < y + 8; j++)
                {
                    if ((i - x + j - y) % 2 == 0)
                    {
                        if (arr[i][j] != 'B')
                            temp2++;
                    }
                    else
                    {
                        if (arr[i][j] != 'W')
                            temp2++;
                    }
                }
            }

            int temp = temp1 < temp2 ? temp1 : temp2;
            if (temp < count)
                count = temp;

            temp1 = 0;
            temp2 = 0;
        }
    }
    
    cout << count;

    return 0;
}