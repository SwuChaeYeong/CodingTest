#include <iostream>
using namespace std;

int main(){
    int x, y;
    
    cin >> x;
    cin >> y;
    
    //1, 4사분면
    if(x > 0)
    {
        if(y > 0)
            cout<<1;
        else if (y < 0)
            cout<<4;
    }
    //2, 3사분면
    else if(x < 0)
    {
        if(y > 0)
            cout<<2;
        else if(y < 0)
            cout<<3;
    }
}