#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    deque<pair<int, int>> dq;

    int size;
    cin >> size;

    for (int i = 1; i <= size; i++)
    {
        int temp;
        cin >> temp;
        dq.push_back(make_pair(i, temp));
    }

    //1번 뺌
    int move = dq.front().second;
    cout << dq.front().first << " ";
    dq.pop_front();

    while (!dq.empty())
    {
        if (move > 0)
        {
            for (int i = 0; i < move - 1; i++)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }

            move = dq.front().second;
            cout << dq.front().first << " ";
            dq.pop_front();
        }
        else
        {
            for (int i = 0; i > move + 1; i--)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }

            move = dq.back().second;
            cout << dq.back().first << " ";
            dq.pop_back();
        }
    }

    return 0;
}