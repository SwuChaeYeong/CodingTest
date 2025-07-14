#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    priority_queue<int, vector<int>, greater<int>> q;

    int N, x;
    cin >> N;

    for (int i = 0; i < N * N; i++)
    {
        cin >> x;
        q.push(x);
        
        if (q.size() > N)
            q.pop();
    }

    cout << q.top();
      
    return 0;
}