#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<unsigned int, unsigned int> a, pair<unsigned int, unsigned int> b)
{
    if (a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N;
    cin >> N;

    vector<pair<unsigned int, unsigned int>> meeting(N);

    for (int i = 0; i < N; i++)
    {
        cin >> meeting[i].first >> meeting[i].second;
    }

    sort(meeting.begin(), meeting.end(), compare);
    
    unsigned int end = meeting[0].second;
    int result = 1;

    for (int i = 1; i < N; i++)
    {
        if (end <= meeting[i].first)
        {
            end = meeting[i].second;
            result++;
        }    
    }

    cout << result;

    return 0;
}