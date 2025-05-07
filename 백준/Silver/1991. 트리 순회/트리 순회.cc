#include <iostream>
#include <unordered_map>
using namespace std;

// 트리 노드
struct Node
{
    char left;
    char right;
};

// 트리 해시
unordered_map<char, Node> tree;

// 전위 순회
void Preorder(char node)
{
    if (node == '.')return;
    cout << node;
    Preorder(tree[node].left);
    Preorder(tree[node].right);
}

// 중위 순회
void Inorder(char node)
{
    if (node == '.')return;
    Inorder(tree[node].left);
    cout << node;
    Inorder(tree[node].right);
}

// 후위 순회
void Postorder(char node)
{
    if (node == '.')return;
    Postorder(tree[node].left);
    Postorder(tree[node].right);
    cout << node;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n;
    cin >> n;

    // 트리 입력
    for (int i = 0; i < n; i++)
    {
        char root, left, right;
        cin >> root >> left >> right;
        tree[root] = { left, right };
    }

    // A부터 순회 시작
    Preorder('A');
    cout << '\n';
    Inorder('A');
    cout << '\n';
    Postorder('A');
    cout << '\n';

    return 0;
}