#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N, x;
    cin >> N;

    priority_queue<int> q;
    for (int i = 0; i < N; i++)
    {
        cin >> x;

        if (x != 0)
        {
            q.push(x);
        }
        else
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
    }
    
    return 0;
}