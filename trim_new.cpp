#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'breakup_sms' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING input_string
 *  2. INTEGER char_limit
 */

vector<string> breakup_sms(string input_string, int char_limit) {
     vector<string> out;
     int i = 0; 
     int cnt = 0;
     int start_idx = 0;
     int prev_idx = 0;
     bool in_word = false;
     bool starting = true;
     for (i; i < input_string.length(); i++) {
         cnt++;
         if (input_string[i] != ' ') {
             //prev_idx = i;
             in_word = true;
             if (starting) {
                 start_idx = i;
                 starting = false;
             }
         }
        else if (input_string[i] == ' ') {
            if (in_word)
                prev_idx = i-1; 
            in_word = false;
        }
        
         if (cnt == char_limit) {
             //cout << start_idx << " " << prev_idx << endl;
             //cout << input_string.substr(start_idx, prev_idx-start_idx+1) << endl;
             if (prev_idx > start_idx)  {
                 out.push_back(input_string.substr(start_idx, prev_idx-start_idx+1));
                 i = prev_idx+1;
              } 
              else  {
                 out.push_back(input_string.substr(start_idx, i-start_idx+1));
                 prev_idx = i;
                 i = i+1;
              }
             cnt = 0;
             starting = true;
         }
         //else {
         //    i++;
         //}
     }
     if (cnt > 0)
         out.push_back(input_string.substr(start_idx, i-1-start_idx+1));
     return out;
} 

//10
//Hey Ian Smithington-Mephisto, your uber is on the way!

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string char_limit_temp;
    getline(cin, char_limit_temp);

    string input_string;
    getline(cin, input_string);

    int char_limit = stoi(ltrim(rtrim(char_limit_temp)));

    vector<string> result = breakup_sms(input_string, char_limit);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    //fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

//20
//Hey Ian, your Uber is arriving now!
