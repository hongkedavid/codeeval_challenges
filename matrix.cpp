#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> multiply(vector<vector<int>>& a, vector<vector<int>>& b) { 
     int a_row = a.size();
     int a_col = a[0].size();
     int b_row = a_col;
     int b_col = b[0].size();
     vector<vector<int>> c;
     for (int i = 0; i < a_row; i++) {
	  c.push_back(vector<int>());
	  for (int j = 0; j < b_col; j++) {
	       int sum = 0;
               for (int k = 0; k < b_row; k++)
                    sum += a[i][k]*b[k][j];
	       c[i].push_back(sum);
	  }
     }
     return c;
}



int main() {
     // a=[1 2 3; 2 3 4]	
     vector<vector<int>> a;
     a.push_back(vector<int>()); a[0].push_back(1); a[0].push_back(2); a[0].push_back(3);
     a.push_back(vector<int>()); a[1].push_back(2); a[1].push_back(3); a[1].push_back(4);
     // b=[1 1 1 1; 2 2 2 2; 1 1 1 1];
     vector<vector<int>> b;
     b.push_back(vector<int>()); b[0].push_back(1); b[0].push_back(1); b[0].push_back(1); b[0].push_back(1);
     b.push_back(vector<int>()); b[1].push_back(2); b[1].push_back(2); b[1].push_back(2); b[1].push_back(2);
     b.push_back(vector<int>()); b[2].push_back(1); b[2].push_back(1); b[2].push_back(1); b[2].push_back(1);
     vector<vector<int>> c = multiply(a, b);
     for (int i = 0; i < c.size(); i++) {
	  for (int j = 0; j < c[0].size(); j++)
	       cout << c[i][j] << " ";
	  cout << endl;
     }
     return 0;
}
