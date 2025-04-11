#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;

    stack<int> st;

    int input;
    int num;

    while (size--)
    {
        cin >> input;

        switch (input)
        {
        case 1:
            cin >> num;
            st.push(num);
            break;

        case 2:
            if (!st.empty())
            {
                cout << st.top() << "\n";
                st.pop();
            }
            else
            {
                cout << -1 << "\n";
            }
            break;

        case 3:
            cout << st.size() << "\n";
            break;

        case 4:
            if (st.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
            break;

        case 5:
            if (!st.empty())
                cout << st.top() << "\n";
            else
                cout << -1 << "\n";
            break;

        default:
            break;
        }
    }

    return 0;
}