#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int** arr1;
    int** arr2;
    int** answer;

    arr1 = (int**)malloc(sizeof(int*) * n);
    arr2 = (int**)malloc(sizeof(int*) * n);
    answer = (int**)malloc(sizeof(int*) * n);

    for (int i = 0; i < n; i++)
    {
        arr1[i] = (int*)malloc(sizeof(int) * m);
        arr2[i] = (int*)malloc(sizeof(int) * m);
        answer[i] = (int*)malloc(sizeof(int) * m);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr1[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr2[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            answer[i][j] = arr1[i][j] + arr2[i][j];
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}