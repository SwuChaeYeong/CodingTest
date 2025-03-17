#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string array[5];
    int wordMax = 0;

    for (int i = 0; i < 5; i++)
    {
        cin >> array[i];

        if (array[i].size() > wordMax)
            wordMax = array[i].size();
    }

    for (int i = 0; i < wordMax; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i < array[j].size())
                cout << array[j][i];
        }
    }

    return 0;
}