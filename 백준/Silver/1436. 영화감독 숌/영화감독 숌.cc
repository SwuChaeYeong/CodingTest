#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string title;

    int count = 0;

    for (int i = 666;; i++)
    {
        title = to_string(i);

        if (title.find("666") != -1)
        {
            count++;

            if (count == n)
            {
                cout << i;
                break;
            }
        }
    }

    return 0;
}