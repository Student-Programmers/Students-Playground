#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    int si , loop = 1, d = 0;
    cout << "Enter the size of diamond > ";
    cin >> si;
    int sa = si - 1;
    string b = "";
    while(loop <= si){
        for(int a = 1 ; a <= sa ; a++ ){
            b += " ";
        }
        for(int c = 1 ; c <= d + (si - sa); c++){
            b += "*";
        }
        cout << b << endl;
        b = "";
        sa--;
        loop++;
        d++;
    }
    loop = 1;
    si--;
    d-=2;
    int sb = si;
    while(loop <= si){
        for(int f = 1 ; f <= loop ; f++){
            b += " ";
        }
        for(int e = 1 ; e <= d + sb ; e++){
            b += "*";
        }
        cout << b << endl;
        b = "";
        loop++;
        sb--;
        d--;
    }
    return 0;
}
