#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    vector<int> ownCard;

    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        ownCard.push_back(temp);
    }
    
    sort(ownCard.begin(), ownCard.end());

    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        cout << binary_search(ownCard.begin(), ownCard.end(), temp) << ' ';
    }

    return 0;
}