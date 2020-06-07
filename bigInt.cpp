#include <iostream>
#include <string>
#include <vector>

using namespace std;

// a = "2531475816458561384564985194"
// b = "3475163434"

// a + b
// a - b
// add(a, b)
// sub(a, b)

string add(string& a, string& b) {
    int d1 = a.length()-1, d2=b.length()-1;
    string s= "";
    int c = 0, t;
    while (d1 >= 0 && d2 >= 0){
        t = ((a[d1]-'0')+(b[d2]-'0')+c) % 10;
        c = ((a[d1]-'0')+(b[d2]-'0')+c) / 10;
        s = string(1, t+'0') + s;
        d1--; d2--;
    }
    while (d1 >= 0) {
        t = ((a[d1]-'0')+c) % 10;
        c = ((a[d1]-'0')+c) / 10;
	s = string(1, t+'0') + s;
        d1--;
    }
    while (d2 >= 0) {
        t = ((b[d2]-'0')+c) % 10;
        c = ((b[d2]-'0')+c) / 10;
	s = string(1, t+'0') + s;
        d2--;
    }
    if (c > 0)
        s = string(1, c+'0') + s;
    return s;
}

string sub(string a, string b) {
    bool neg_flag = false;
    int lz = 0;
    if (a.length() < b.length())
	neg_flag = true;
    else if (a.length()==b.length()) {
	for (int i = 0; i < a.length(); i++) {
             if (a[i] < b[i]) {
                 neg_flag = true;
                 break;
             }
	     lz++;
        }
    } 
    if (neg_flag) {
        string tmp = b;
        b = a;
        a = tmp;
    }
    int d1 = a.length()-1, d2=b.length()-1;
    string s= "";
    int c = 0, t;
    while (d1 >= 0 && d2 >= 0) {
        if (a[d1]-b[d2]+c < 0) {
            t = a[d1]-b[d2]+c+10;
            c = -1;
        }
        else {
            t = a[d1]-b[d2]+c;
            c = 0;
        }
	s = string(1, t+'0') + s;
        d1--; d2--;
    }
    while (d1 >= 0) {
        if (a[d1]-'0'+c < 0) {
            t = a[d1]-'0'+c+10;
            c = -1;
        }
        else {
            t = a[d1]-'0'+c;
            c = 0;
        }
        s = string(1, t+'0') + s;
        d1--;
    }
    if (neg_flag) {
        s = string(1, '-') + s.substr(lz);
    }
    return s;
}

int main() {
   string a = "4"; //"2531475816458561384564985194";
   string b = "7"; //"3475163434";

   cout << add(a, b) << endl;
   cout << sub(a, b) << endl;

   return 0;
}

