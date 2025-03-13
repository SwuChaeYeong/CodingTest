#include <iostream>
using namespace std;

int main(){
    int hour, minute;
    cin >> hour >> minute;
    
    if (minute < 45)
    {
        minute += 15;
        
        if(hour == 0)
            hour = 23;
        else 
            hour -= 1;
    }
    else
    {
        minute -= 45;
    }
    
    cout << hour << " " << minute;
    
    return 0;
}