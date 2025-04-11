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

    while (size--)
    {
        cin >> input;

        if (input == 0)
            st.pop();
        else
            st.push(input);
    }

    int len = st.size();
    int sum = 0;

    for (int i = 0; i < len; i++)
    {
        sum += st.top();
        st.pop();
    }

    cout << sum;

    return 0;
}