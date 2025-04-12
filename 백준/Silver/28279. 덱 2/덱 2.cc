#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    deque<int> dq;

    int size, input, num;
    cin >> size;

    while (size--)
    {
        cin >> input;

        switch (input)
        {
        case 1:
            cin >> num;
            dq.push_front(num);
            break;

        case 2:
            cin >> num;
            dq.push_back(num);
            break;

        case 3:
            if (!dq.empty())
            {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
            else
            {
                cout << -1 << "\n";
            }
            break;

        case 4:
            if (!dq.empty())
            {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
            else
            {
                cout << -1 << "\n";
            }
            break;

        case 5:
            cout << dq.size() << "\n";
            break;

        case 6:
            cout << dq.empty() << "\n";
            break;

        case 7:
            if (!dq.empty())
            {
                cout << dq.front() << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
            break;

        case 8:
            if (!dq.empty())
            {
                cout << dq.back() << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
            break;
        }
    }

    return 0;
}