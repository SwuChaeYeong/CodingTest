#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct compare
{
    bool operator() (int a, int b)
    {
        int n1 = abs(a);
        int n2 = abs(b);

        if (n1 == n2)
            return a > b;

        else
            return n1 > n2;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    priority_queue<int, vector<int>, compare> q;

    int N, x;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x;

        if (x == 0)
        {
            if (q.empty())
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << q.top() << '\n';
                q.pop();
            }
        }
        else
        {
            q.push(x);
        }
    }
      
    return 0;
}