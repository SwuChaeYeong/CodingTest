#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> split(const string& s, char d)
{
    vector<string> pieces;
    string piece;
    stringstream ss(s);

    while (getline(ss, piece, d))
    {
        pieces.push_back(piece);
    }

    return pieces;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    string str;
    cin >> str;

    vector<string> minusSplit = split(str, '-');

    int result = 0;

    for (int i = 0; i < minusSplit.size(); i++)
    {
        int temp = 0;

        vector<string> plusSplit = split(minusSplit[i], '+');

        for (int j = 0; j < plusSplit.size(); j++)
        {
            temp += stoi(plusSplit[j]);
        }

        if (i == 0)
            result += temp;
        else
            result -= temp;
    }

    cout << result;

    return 0;
}