#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string myString) {
    
    transform(myString.begin(), myString.end(), myString.begin(), ::tolower);
    
    for (int i = 0; i < myString.length(); i++)
    {
        if (myString[i] == 'a')
            myString[i] = 'A';
    }
    
    return myString;
}