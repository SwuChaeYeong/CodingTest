#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 배열 입력
    int N, M;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    // 정렬
    sort(v.begin(), v.end());

    // 찾을 숫자 개수
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        // 찾을 숫자
        int target;
        cin >> target;

        cout << binary_search(v.begin(), v.end(), target) << '\n';
    }
    
    return 0;
}