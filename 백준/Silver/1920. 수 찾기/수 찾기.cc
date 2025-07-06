#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

bool binarySearch(const vector<int>& arr, int target)
{
    int start = 0, end = N - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        // 찾을 값이면
        if (arr[mid] == target)
        {
            return true;
        }
        // 찾을 값보다 중앙이 작으면 시작점을 중앙으로 바꿈
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        // 찾을 값보다 중앙이 크면 끝점을 중앙으로 바꿈
        else
        {
            end = mid - 1;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 배열 입력
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

        cout << binarySearch(v, target) << '\n';
    }
    
    return 0;
}