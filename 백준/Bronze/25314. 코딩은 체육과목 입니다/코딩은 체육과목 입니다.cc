#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    
    num /= 4;
    
    for (int i=0; i<num; i++){
        cout << "long ";
    }
    
    cout<<"int";
    
    return 0;
}