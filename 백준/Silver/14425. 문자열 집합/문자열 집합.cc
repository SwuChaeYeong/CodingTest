#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    int findSize;

    vector<string> onwWord;

    cin >> size >> findSize;

    for (int i = 0; i < size; i++)
    {
        string temp;
        cin >> temp;
        onwWord.push_back(temp);
    }
    
    sort(onwWord.begin(), onwWord.end());    
    int result = 0;

    for (int i = 0; i < findSize; i++)
    {
        string temp;
        cin >> temp;
        if (binary_search(onwWord.begin(), onwWord.end(), temp))
            result++;
    }

    cout << result;

    return 0;
}