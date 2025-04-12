#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    //자료구조 개수
    cin >> n;

    //자료구조 뭔지
    vector<int> data;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        data.push_back(temp);
    }

    deque<int> dq;

    //들어 있는 정수 입력
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        //큐인 경우에만
        if (data[i] == 0)
            dq.push_back(temp);

    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;

        dq.push_front(temp);
        cout << dq.back() << " ";
        dq.pop_back();
    }

    return 0;
}