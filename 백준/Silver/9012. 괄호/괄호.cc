#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;

    while (size--)
    {
        stack<char> st;
        string parenthesis;
        string result = "YES";

        cin >> parenthesis;

        for (int i = 0; i < parenthesis.length(); i++)
        {
            switch (parenthesis[i])
            {
            case '(':
                st.push(parenthesis[i]);
                break;

            case ')':
                if (st.empty())
                {
                    result = "NO";
                    break;
                }
                else
                    st.pop();
                break;
            }
        }

        if (!st.empty())
            result = "NO";

        cout << result << "\n";
    }

    return 0;
}