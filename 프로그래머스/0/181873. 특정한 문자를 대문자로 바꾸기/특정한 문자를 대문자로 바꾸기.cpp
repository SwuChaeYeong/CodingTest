#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string my_string, string alp) {
    
    for (int i = 0; i < my_string.length(); i++)
    {
        if (my_string[i] == alp[0])
            my_string[i] = toupper(my_string[i]);
    }
    
    return my_string;
}