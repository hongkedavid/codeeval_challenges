#include <iostream> 
#include <stack> 
using namespace std; 

string recurPost(string& pre_exp, int l, int r) {
  if (l == r)
      return string(1, pre_exp[l]);
  int m = l+1;
  int oprand = 0, optor = 0;
  while (m <= r) {
    if (pre_exp[m] != '+' && pre_exp[m] != '*' && pre_exp[m] != '-' && pre_exp[m] != '/')
        oprand++;
    else
        optor++;
    if (oprand - optor == 1)
        break;
    m++;
  }
  return recurPost(pre_exp, l+1, m) + recurPost(pre_exp, m+1, r) + pre_exp[l];
}

string preToPost(string pre_exp) {
  return recurPost(pre_exp, 0, pre_exp.length()-1);  
}

string postToPre(string post_exp) {
  stack<string> st;
  for (auto s : post_exp) {
    if (s != '+' && s != '*' && s != '-' && s != '/')
        st.push(string(1, s));
    else {
        string out = "";
        out = st.top() + out;
        st.pop();
        out = st.top() + out;
        st.pop();
        out = s + out;
        st.push(out);
    }
  }
  return st.top();
}

int main() { 
  string pre_exp = "*-A/BC-/AKL"; // (A-B/C)*(A/K-L)
  string post_exp = "ABC/-AK/L-*"; // (A-B/C)*(A/K-L)
  cout << "Postfix : " << preToPost(pre_exp) << endl; // ABC/-AK/L-* 
  cout << "Prefix : " << postToPre(post_exp) << endl; // *-A/BC-/AKL
  return 0; 
} 
