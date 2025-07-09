#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int N, k;
	cin >> N >> k;

	//여기부터 이분탐색
	//low high mid모두 값임
	//cnt는 mid보다 같거나 작은 수의 갯수를 의미
	int low = 1, high = k; //원래 N*N인데 항상 B[k]<k 라서 k로 해도 됨
	while (low < high) {
		int mid = (low + high) / 2, cnt = 0;

		//개수 세는 부분!
		for (int i = 1; i <= N; i++) {
			cnt += min(N, mid / i);
		}
        //
		
		if (cnt < k) low = mid + 1;
		else high = mid;
	}

	cout << high << '\n';
}