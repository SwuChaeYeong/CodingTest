#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n;
    cin >> n;

    int prev[3] = { 0, 0, 0 };

    for (int i = 0; i < n; i++)
    {
        int cost[3];
        cin >> cost[0] >> cost[1] >> cost[2];

        int curr[3];
        
        curr[0] = min(prev[1], prev[2]) + cost[0];
        curr[1] = min(prev[0], prev[2]) + cost[1];
        curr[2] = min(prev[0], prev[1]) + cost[2];

        for (int j = 0; j < 3; j++)
            prev[j] = curr[j];
    }

    cout << min({ prev[0], prev[1], prev[2] });

    return 0;
}