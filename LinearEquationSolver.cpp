#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

string sr(string a){
    string b = "";
    int c = 0;
    while(c <= a.length()){
        if(a[c] != ' '){
            b += a[c];
        }
        c++;
    }
    return b;
}

bool checkint(char a){
    if(a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9'){
        return true;
    }else{
        return false;
    }
}

bool checksign(char a){
    if(a == '-'){
        return true;
    }else{
        return false;
    }
}

bool checkx(char a){
    if(a == 'x'){
        return true;
    }else{
        return false;
    }
}

bool checkdot(char a){
    if(a == '.'){
        return true;
    }else{
        return false;
    }
}

bool eos(int a, int b){
    if(b > a){
        return false;
    }else{
        return true;
    }
}

bool eos1(int fnd, int c, int len){
    if(fnd+c > len){
        return false;
    }else{
        return true;
    }
}

double divide(string a){
    int noint = 1;
    int leng = a.length();
    double Nu, De, Re;
    string inte;
    size_t found;
    stringstream s1;
    stringstream s2;
    bool main_loop = true;

    found = a.find("/",0);
    if(found != string::npos){
        while((checkint(a[found-noint]) || checksign(a[found-noint])) && eos(found, noint)){
            noint++;
        }
        inte = a.substr(found-(noint-1),noint-1);
        s1 << inte;
        s1 >> Nu;
        noint = 1;
        inte = "";
        while((checkint(a[found+noint]) || checksign(a[found+noint])) && eos1(found, noint, leng)){
            noint++;
        }
        inte = a.substr(found+1,noint-1);
        s2 << inte;
        s2 >> De;
    }
    Re = (Nu / De);
    return Re;
}

string bre(string a)
{
    int len = a.length();
    int b = 0;
    size_t fi;
    while(b <= len){
        fi = a.find("(",b);
        if(fi != string::npos && checkint(a[fi-1])){
            a[fi] = '*';
        }
        b++;
    }
    int c = 0;
    size_t fn;
    while(c <= len){
        fn = a.find("(",c);
        if(fn != string::npos){
            a[fn] = ' ';
        }
        c++;
    }
    c = 0;
    fn = 0;
    while(c <= len){
        fn = a.find(")",c);
        if(fn != string::npos){
            a[fn] = ' ';
        }
        c++;
    }
    return a;
}

int main()
{
  return 0;
}
