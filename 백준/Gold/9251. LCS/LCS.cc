#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    string A, B;
    cin >> A >> B;

    int Alength = A.length();
    int Blength = B.length();

    int dp[1001][1001] = { 0 };

    for (int i = 1; i <= Alength; i++)
    {
        for (int j = 1; j <= Blength; j++)
        {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[Alength][Blength];

    return 0;
}