#include <iostream>
using namespace std;

int main()
{
    int hour, min, time;
    
    cin >> hour >> min;
    cin >> time;
    
    min += time;
    
    hour = hour + min/60;
    min %= 60;
    
    if(hour >= 24)
        hour -= 24;
    
    cout << hour << " " << min;
    
    return 0;
}