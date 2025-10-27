#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Node
{
    int num;
    string command;
};

int D(int n) { return (2 * n) % 10000; }
int S(int n) { return (n == 0) ? 9999 : n - 1; }
int L(int n) { return (n % 1000) * 10 + n / 1000; }
int R(int n) { return (n / 10) + (n % 10) * 1000; }


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int T;
    cin >> T;

    while (T--) 
    {
        int A, B;
        cin >> A >> B;

        vector<bool> visited(10000, false);
        queue<Node> q;
        q.push({ A, "" });
        visited[A] = true;

        while (!q.empty()) 
        {
            Node cur = q.front();
            q.pop();

            if (cur.num == B) 
            {
                cout << cur.command << '\n';
                break;
            }

            int next;

            // D
            next = D(cur.num);
            if (!visited[next]) 
            {
                visited[next] = true;
                q.push({ next, cur.command + 'D' });
            }

            // S
            next = S(cur.num);
            if (!visited[next]) 
            {
                visited[next] = true;
                q.push({ next, cur.command + 'S' });
            }

            // L
            next = L(cur.num);
            if (!visited[next]) 
            {
                visited[next] = true;
                q.push({ next, cur.command + 'L' });
            }

            // R
            next = R(cur.num);
            if (!visited[next]) 
            {
                visited[next] = true;
                q.push({ next, cur.command + 'R' });
            }
        }
    }

    return 0;
}