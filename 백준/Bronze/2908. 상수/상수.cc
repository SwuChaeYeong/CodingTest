#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num1, num2;
    string str1, str2;

    cin >> str1 >> str2;
    
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    num1 = stoi(str1);
    num2 = stoi(str2);

    num1 >= num2 ? cout << num1 : cout << num2;

    return 0;
}