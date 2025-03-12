#include <iostream>
using namespace std;

int main(){
    double a,b;
    
    cin >> a >> b;
    //오차 10-9 이하
    cout.precision(10);
    cout << a/b;
    
    return 0;
}