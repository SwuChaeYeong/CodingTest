#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        int max = 0;
        int index = 0;

        int line[3];
        cin >> line[0] >> line[1] >> line[2];

        if (line[0] == 0 && line[1] == 0 && line[2] == 0)
            break;

        for (int i = 0; i < 3; i++)
        {
            if (line[i] > max)
                max = line[i];
        }

        if ((line[0] + line[1] + line[2]) <= max * 2)
        {
            cout << "Invalid\n";
        }
        else if ((line[0] == line[1]) && (line[1] == line[2]))
            cout << "Equilateral\n";
        else if ((line[0] != line[1]) && (line[1] != line[2]) && (line[0] != line[2]))
            cout << "Scalene\n";
        else
            cout << "Isosceles\n";
    }

    return 0;
}