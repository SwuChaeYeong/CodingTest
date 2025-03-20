#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        int num;
        int sum = 0;
        cin >> num;

        vector<int> v;

        if (num == -1)
            break;

        for (int i = 1; i < num; i++)
        {
            if (num % i == 0)
            {
                sum += i;
                v.push_back(i);
            }
        }

        if (sum == num)
        {
            cout << num << " = ";
            for (int i = 0; i < v.size() - 1; i++)
            {
                cout << v[i] << " + ";
            }
            cout << v[v.size() - 1] << "\n";
        }
        else
        {
            cout << num << " is NOT perfect.\n";
        }
    }

    return 0;
}