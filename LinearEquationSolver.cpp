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

bool eos(int fnd, int noint){
    if(fnd < noint){
        return false;
    }else{
        return true;
    }
}

bool seos(int fnd){
    if(fnd == 0){
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

double sttoin(string a){
    stringstream ss;
    double b;
    ss << a;
    ss >> b;
    return b;
}

string intost(float a){
    stringstream ss;
    string b;
    ss << a;
    ss >> b;
    return b;
}

string op(string a, int be, int af){
    int h = 0;
    int leng = a.length();
    double Nu, De, Re;
    string inte, r1, r2 = "";
    size_t found;
    stringstream s3;
    found = (leng - af) - 1;
    inte = a.substr(found-be,be);
    Nu = sttoin(inte);
    inte = "";
    inte = a.substr(found+1,af);
    De = sttoin(inte);
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

string sum(string a){
    int len = a.length(), b = 0 , c = 1 , noint = 1 , e = 0;
    float x[256], i[256], tx = 0, d = 0, ti = 0;
    string fx , fi, q;
    size_t fnd;
    while (b <= len){
        fnd = a.find('x',b);
        if(fnd != string::npos){
            while((checkint(a[fnd-noint]) || checkdot(a[fnd-noint]) || checkx(a[fnd-noint])) && seos(fnd-(noint-1))){
                noint++;
            }
            noint--;
            if(noint == 0){
                x[c] = 1;
            }else{
                x[c] = sttoin(a.substr((fnd-noint),noint));
            }
            if(a[(fnd-noint)-1] == '-' && !(fnd == 0)){
                x[c] *= -1;
            }
            c++;
            for(int lo = 0; lo <= noint; lo++){
                a[fnd-lo] = ' ';
            }
            if(a[(fnd-noint)-1] == '+' || a[(fnd-noint)-1] == '-'){
                a[(fnd-noint)-1] = ' ';
            }
            noint = 1;
        }
        if(fnd != string::npos){
            b = fnd+1;
        }else{
            a = sr(a);
            for(int loo = 1; loo <= (c-1); loo++){
                tx += x[loo];
            }
            c = 1;
            fx = intost(tx);
            fx += 'x';
            len = a.length();
            len--;
            while(e < len){
                while(!(checkint(a[d]))){
                    d++;
                }
                noint = 0;
                while((checkint(a[d+noint]) || checkdot(a[d+noint])) && eos1(d, noint, len)){
                    noint++;
                }
                i[c] = sttoin(a.substr(d,noint));
                c++;
                for(int loot = 0; loot < noint; loot++){
                    a[d-loot] = ' ';
                }
                if(a[(d+(noint-1))-1] == '-'){
                    i[c-1] *= -1;
                }
                if(!((d+noint-2) == -1)){
                    a[(d+(noint-1))-1] = ' ';
                }
                e = d+noint;
                d++;
            }
            for(int loop = 1; loop <= (c-1); loop++){
                ti += i[loop];
            }
            fi = intost(ti);
            if(fi[0] == '-'){
                if(fx[0] == '0'){
                    q = fi;
                }else{
                    q = fx + fi;
                }
            }else{
                if(fx[0] == '0'){
                    q = fi;
                }else if(fi[0] == '0'){
                    q = fx;
                }else if((fx[0] == '0') || (fi[0] == '0')){
                    q = '0';
                }else{
                    q = fx + '+' + fi;
                }
            }
            b = len + 1;
        }
    }
    return q;
}

string besum(string f){
    int found, noint = 0;
    found = (f.length())-1;
    while(!(checkint(f[found-noint]) || checkdot(f[found-noint]) || checkx(f[found-noint])) && !eos(found, noint)){
        noint++;
    }
    f = f.substr(0, found-noint-1);
    return f;
}

string solve(string a){
    a = operat(a,'/');
    a = operat(a,'*');
    a = besum(a);
    a = sum(a);
    return a;
}

int main()
{
    string f = "2*2x+1x/2";
    cout << solve(f) << endl;
    return 0;
}
