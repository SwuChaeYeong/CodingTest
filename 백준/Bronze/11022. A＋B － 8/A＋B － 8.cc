#include <iostream>
using namespace std;

int main()
{    
    int num;
    cin >> num;
    
    for(int i=0; i<num; i++){
        int a, b;
        cin>>a>>b;
        cout<< "Case #" << i+1 << ": " << a << " + " << b << " = " << a+b <<"\n";
    }
    
    return 0;
}