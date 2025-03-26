#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num;
    cin >> num;

    int count = 0;

    if (num % 5 == 0)
    {
        cout << num / 5;
    }
    else
    {
        while (num > 0)
        {
            num -= 3;
            count++;

            if (num % 5 == 0)
            {
                count += num / 5;
                cout << count;
                break;
            }
            else if (num == 1 || num == 2)
            {
                cout << -1;
                break;
            }
            else if (num == 0)
            {
                cout << count;
                break;
            }
        }
    }

    return 0;
}