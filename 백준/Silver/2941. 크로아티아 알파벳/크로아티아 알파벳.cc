#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string croatia[8] = { "c=","c-","dz=","d-","lj","nj","s=","z="};

    string word;
    cin >> word;

    for (int i = 0; i < 8; i++)
    {
        while (true)
        {
            if (word.find(croatia[i]) != string::npos)
            {
                word.replace(word.find(croatia[i]), croatia[i].length(), "*");
            }
            else 
            {
                break;
            }
        }
    }

    cout << word.length();

    return 0;
}