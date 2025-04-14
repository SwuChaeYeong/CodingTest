#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int cnt[8001] = { 0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;

    vector<int> v;

    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;

        sum += temp;

        v.push_back(temp);

        ++cnt[temp + 4000];
    }

    sort(v.begin(), v.end());

    int max = -1;
    vector<int> save;

    for (int i = 0; i < 8001; i++)
    {
        if (cnt[i] > max)
        {
            save.clear();
            max = cnt[i];
            save.push_back(i - 4000);
        }
        else if (max == cnt[i])
        {
            save.push_back(i - 4000);
        }
    }

    cout << round((double)sum / size) + 0.0f << "\n";
    cout << v[size / 2] << "\n";
    cout << (save.size() == 1 ? save.front() : save[1]) << "\n";
    cout << v.back() - v.front();

    return 0;
}