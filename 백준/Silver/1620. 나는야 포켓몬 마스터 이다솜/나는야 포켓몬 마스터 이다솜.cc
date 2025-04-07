#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 문자 입력 > 숫자 출력
    map<string, int> num;
    // 숫자 입력 > 문자 출력
    string name[100001];

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;

        name[i] = temp;
        num[temp] = i;
    }

    for (int i = 0; i < m; i++)
    {
        string temp;
        cin >> temp;

        //문자인 경우
        if (atoi(temp.c_str()) == 0)
        {
            cout << num[temp] + 1 << "\n";
        }
        else
        {
            cout << name[atoi(temp.c_str()) - 1] << "\n";
        }
    }

    return 0;
}