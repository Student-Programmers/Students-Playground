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

string op(string a, int be, int af){
    int h = 0;
    int leng = a.length();
    double Nu, De, Re;
    string inte, r1, r2 = "";
    size_t found;
    stringstream s1;
    stringstream s2;
    stringstream s3;
    found = (leng - af) - 1;
    inte = a.substr(found-be,be);
    s1 << inte;
    s1 >> Nu;
    inte = "";
    inte = a.substr(found+1,af);
    s2 << inte;
    s2 >> De;
    if(a[found] == '/'){
        Re = (Nu / De);
    }
    if(a[found] == '*'){
        Re = (Nu * De);
    }
    s3 << Re;
    s3 >> r1;
    if(r1.length() < leng){
        r2 += r1;
        h = leng - r1.length();
        for(int lo = 1 ; lo <= h ; lo++ ){
            r2 += ' ';
        }
    }else if(r1.length() > leng){
        r2 = r1.substr(0,leng);
    }else{
        r2 = r1;
    }
    return r2;
}

string operat(string a, char opr)
{
    int b = 0, be, af, noint = 1, chr, cont = 0;
    string frac, ans;
    size_t found;
    int len = a.length();
    while(b < len){
        found = a.find(opr,b);
        if(found == string::npos){
            b = len;
        }else{
            while((checkint(a[found-noint]) || checkdot(a[found-noint]) || checkx(a[found-noint])) && eos(found, noint)){
                noint++;
            }
            be = noint - 1;
            noint = 1;
            while((checkint(a[found+noint]) || checkdot(a[found+noint])) && eos1(found, noint, len)){
                noint++;
            }
            af = noint - 1;
            noint = 1;
            if(a[found-1] == 'x'){
                a[found-1] = opr;
                found--;
                for(int s = 1; s <= af; s++){
                    a[found+s] = a[found+(s+1)];
                }
                a[found+af+1] = 'x';
                be--;
            }
            chr = be+af+1;
            frac = a.substr(found-be,chr);
            ans = op(frac,be,af);
            for(int lo = 1; lo <= chr; lo++){
                a[(found-be)+cont] = ans[lo-1];
                cont++;
            }
            cont = 0;
        }
        if(found == string::npos){
            b = len;
        }
    }
    return sr(a);
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
    return sr(a);
}

int main()
{
    string f = "34x*2+35x/7=45";
    string g;
    cout << f  << endl;
    g = operat(f,'/');
    cout << g << endl;
    cout << operat(g,'*') << endl;
    return 0;
}
