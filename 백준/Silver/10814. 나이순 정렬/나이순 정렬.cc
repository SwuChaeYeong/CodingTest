#include <iostream>
#include <algorithm>

using namespace std;

struct Member
{
    int num;
    int age;
    string name;
};

bool compare(Member a, Member b)
{
    if (a.age == b.age)
        return a.num < b.num;
    else
        return a.age < b.age;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;

    Member arr[100001];

    for (int i = 0; i < size; i++)
    {
        arr[i].num = i;
        cin >> arr[i].age >> arr[i].name;
    }

    sort(arr, arr + size, compare);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i].age << " " << arr[i].name << "\n";
    }

    return 0;
}