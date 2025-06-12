#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n, m;
    cin >> n >> m;

    long long sum = 0;
    long long result = 0;

    vector<long long> psumCnt(m, 0);
    psumCnt[0] = 1;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        
        sum = (sum + num) % m;      // 누적합의 나머지
        result += psumCnt[sum];     // 지금까지 같은 나머지 개수만큼 더하기
        psumCnt[sum]++;             // 현재 나머지 개수 추가
    }

    cout << result;

    return 0;
}