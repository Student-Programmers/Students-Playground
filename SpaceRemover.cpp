#include <iostream>
#include <cstring>
using namespace std;

int main(){
    //Declaring variables
    int n = 0, m = 0, s = 0, q = 0, r, len;
    int p[10000];
    string a;
    //Getting input
    cout << "Enter a string >" <<endl;
    getline(cin,a);
    //Checking length of given string
    len = a.length();
    //Checking for spaces and characters
    while(n <= len){
        if(a[n] != ' '){
            m++;
        } else{
            s++;
            p[q] = n;
            q++;
        }
        n++;
    }
    //Reintialing Variables
    char b[m];
    n = 0;
    q = 0;
    m = 0;
    //Preparing for output
    while(n <= len){
        if(n == p[q]){
            q++;
        } else{
            b[m] = a[n];
            m++;
        }
        n++;
    }
    m -= 2;
    //Giving Output
    cout << endl;
    cout << endl;
    cout << "Your string is >";
    for(int o = 0; o <= m; o++){
        cout << b[o];
    }
    cout << endl;
    cout << endl;
    //Checking for Errors
    if(m+1 != len-s){
        cout << "It's not working properly.";
    }

    return 0;
}
