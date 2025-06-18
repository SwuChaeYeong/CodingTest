#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    string str;
    cin >> str;

    int result = 0, num = 0;
    bool isMinus = false;

    for (int i = 0; i <= str.size(); i++)
    {
        // -, +, 문자열 끝인 경우 지금까지 나온 숫자를 결과에 반영
        if (i == str.size() || str[i] == '+' || str[i] == '-')
        {
            // 마이너스 이후면 빼고
            if (isMinus)
                result -= num;
            // 그 전이면 더함
            else
                result += num;

            // 다음 숫자 계산을 위해 초기화
            num = 0;

            // -를 만났다면 변수를 true로 바꿔줌
            if (i < str.size() && str[i] == '-')
                isMinus = true;
        }
        // 문자가 숫자인 경우 num에 자리수별로 누적
        else
        {
            num = num * 10 + (str[i] - '0');
        }
    }

    cout << result;

    return 0;
}