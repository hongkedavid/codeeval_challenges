#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    struct Keyword {
        string key;
        int val;
    };
    class cost_comparator {
      public:
    	cost_comparator() {}
        bool operator() (const Keyword& lhs, const Keyword& rhs) {
            return (lhs.val > rhs.val);
        }
    };
    int lexSum(string word) {
        int s = 0;
        for (int i = 0; i < word.length(); i++) 
            s += word[i];
        return s;
    }
    void topThree(vector<vector<string>>& out, priority_queue<Keyword, vector<Keyword>, cost_comparator>& prefix) {
        vector<string> v;
	vector<Keyword> tmp;
	int t = 0;
        while (!prefix.empty()) {
            Keyword k = prefix.top();
	    tmp.push_back(k);
            v.push_back(k.key);
            prefix.pop();
            t++;
            if (t == 3)
                break;
        }
	out.push_back(v);
	for (auto k : tmp)
	    prefix.push(k);
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> out;
        if (searchWord.length() == 0)
            return out;
        priority_queue<Keyword, vector<Keyword>, cost_comparator> prefix;
        for (int i = 0; i < products.size(); i++) {
            if (products[i][0] == searchWord[0]) 
                prefix.push({products[i], lexSum(products[i])});
        }
        topThree(out, prefix);
        for (int i = 1; i < searchWord.length(); i++) {
            vector<Keyword> tmp;
	    while (!prefix.empty()) {
		Keyword p = prefix.top();
		prefix.pop();
		if (p.key[i] == searchWord[i])
                    tmp.push_back(p);
            }
	    for (auto k : tmp)
                prefix.push(k);
            topThree(out, prefix);
        }
        return out;
    }
};

int main() { 
    Solution s;
}
