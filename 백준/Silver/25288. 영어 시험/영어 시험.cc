#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int N;
    string S;
    cin >> N >> S;

    for (int i = 0; i < N; i++)
    {
        cout << S;
    }

    return 0;
}