#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        stack<char> st;
        string parenthesis;
        string result = "yes";

        getline(cin, parenthesis);

        if (parenthesis == ".")
            break;

        for (int i = 0; i < parenthesis.length(); i++)
        {
            switch (parenthesis[i])
            {
            case '(': case '{': case '[':
                st.push(parenthesis[i]);
                break;

            case ')': case '}': case ']':
                if (st.empty())
                {
                    result = "no";
                    break;
                }
                else
                {
                    char prev = st.top();
                    if (parenthesis[i] == ')' && prev != '(' || parenthesis[i] == '}' && prev != '{' || parenthesis[i] == ']' && prev != '[')
                    {
                        result = "no";
                        break;
                    }
                    else
                    {
                        st.pop();
                    }
                }
                break;
            }
        }

        if (!st.empty())
            result = "no";

        cout << result << "\n";
    }

    return 0;
}