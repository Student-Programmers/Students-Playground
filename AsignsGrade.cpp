#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    double percentage, div, per, tmarks, omarks;
    string grade;

    cout << "Enter total marks: " << endl;
    cin >> tmarks;
    cout << "Enter obtained marks: " << endl;
    cin >> omarks;

    tmarks /= 1.0;
    omarks /= 1.0;
    div = omarks / tmarks;
    percentage = (div * 100);
    per = round(percentage);

    if(per >= 90){
        grade = "A+";
    } else if(per >= 80) {
        grade = "A";
    } else if(per >= 70) {
        grade = "B";
    } else if(per >= 60) {
        grade = "C";
    } else if(per >= 50) {
        grade = "D";
    } else if(per >= 33) {
        grade = "E";
    } else {
        grade = "F";
    }
    cout << "Your grade is " << grade << endl;

    return 0;
}
