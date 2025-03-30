#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct map {
    int x;
    int y;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;

    vector<long long int> list(size);

    for (int i = 0; i < size; i++)
    {
        cin >> list[i];
    }

    vector<long long int> sortList(list);
    sort(sortList.begin(), sortList.end());
    sortList.erase(unique(sortList.begin(), sortList.end()), sortList.end());

    for (int i = 0; i < size; i++)
    {
        cout << lower_bound(sortList.begin(), sortList.end(), list[i]) - sortList.begin()  << " ";
    }

    return 0;
}