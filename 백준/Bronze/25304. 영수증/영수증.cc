#include <iostream>
using namespace std;

int main()
{
    int total;
    int num;
    int result = 0;
    
    cin >> total;
    cin >> num;
    
    for (int i=0;i<num;i++)
    {
        int price, count;
        cin >> price >> count;
        
        result += price * count;
    }
    
    result==total?cout<<"Yes":cout<<"No";  
    
    return 0;
}