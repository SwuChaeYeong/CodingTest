#include <iostream>
using namespace std;

int preorder[10001];
int i;

void post(int start, int end)
{
    if (start >= end)
        return;
    
    // 전위 순회 루트 -> 왼쪽 서브트리 -> 오른쪽 서브트리
    for (i = start + 1; i < end; i++)
    {
        if (preorder[start] < preorder[i])
            break;
    }

    // 왼쪽
    post(start + 1, i);
    //오른쪽
    post(i, end);

    cout << preorder[start] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n = 0, x;

    // 입력이 몇 개인지 모르므로
    while (cin >> x)
    {
        preorder[n++] = x;
    }

    post(0, n);

    return 0;
}