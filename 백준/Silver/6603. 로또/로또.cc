#include <iostream>
#include <vector>
using namespace std;

vector<int> s;
vector<int> selected;
int n;

void lotto(int start, int depth)
{
    if (depth == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << selected[i] << " ";
        }
        cout << '\n';

        return;
    }

    for (int i = start; i < n; i++)
    {
        selected.push_back(s[i]);
        lotto(i + 1, depth + 1);
        selected.pop_back();
    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    while (true)
    {
        cin >> n;

        if (n == 0)
            break;

        s.clear();
        selected.clear();

        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;

            s.push_back(temp);
        }

        lotto(0, 0);
        
        cout << '\n';

    }
    return 0;
}