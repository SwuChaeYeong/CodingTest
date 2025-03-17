#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    float credit[20];     //학점
    string grade[20];  //등급
    string subject[20]; //과목명

    float totalCredit = 0;
    float totalGrade = 0;

    for (int i = 0; i < 20; i++) {
        cin >> subject[i] >> credit[i] >> grade[i];

        totalCredit += credit[i];

        if (grade[i].compare("A+") == 0)
            totalGrade += (credit[i] * 4.5f);
        else if (grade[i].compare("A0") == 0)
            totalGrade += (credit[i] * 4.0f);
        else if (grade[i].compare("B+") == 0)
            totalGrade += (credit[i] * 3.5f);
        else if (grade[i].compare("B0") == 0)
            totalGrade += (credit[i] * 3.0f);
        else if (grade[i].compare("C+") == 0)
            totalGrade += (credit[i] * 2.5f);
        else if (grade[i].compare("C0") == 0)
            totalGrade += (credit[i] * 2.0f);
        else if (grade[i].compare("D+") == 0)
            totalGrade += (credit[i] * 1.5f);
        else if (grade[i].compare("D0") == 0)
            totalGrade += (credit[i] * 1.0f);
        else if (grade[i].compare("F") == 0)
            totalGrade += 0.0f;
        else
            totalCredit -= credit[i];
    }

    cout << totalGrade / totalCredit;

    return 0;
}