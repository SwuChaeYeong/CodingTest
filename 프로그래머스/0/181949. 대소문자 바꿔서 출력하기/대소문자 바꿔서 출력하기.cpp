#include <iostream>
#include <string>

using namespace std;

int main(void) {
    
    string str;
    cin >> str;
    
    for (int i = 0 ; i < str.length(); i++)
    {
        // 소문자
        if (str[i] >= 'a')
            str[i] = str[i] - 32;
        
        // 대문자
        else
            str[i] = str[i] + 32;
    }
    
    cout << str;
    
    return 0;
}