/* 
Longest Substring with At Most K Distinct Characters
Given a string, find the length of the longest substring T that contains at most k distinct characters.

Example 1:
Input: s = "eceba", k = 2
Output: 3
Explanation: T is "ece" which its length is 3.

Example 2:
Input: s = "aa", k = 1
Output: 2
Explanation: T is "aa" which its length is 2.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> freq;
        int total = 0, left = 0, right = 0;
        int max_cnt = 0;
	bool right_slided = true;
        while (right < s.length()) {
            if (right_slided) {
		if (freq.find(s[right]) == freq.end()) {
                    freq[s[right]] = 1;
                    total++;
                }
                else {
                   freq[s[right]]++;
                }
	    }
            if (total > k) {
		freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    total--;
                    freq.erase(s[left]);
                }
                left++;
		right_slided = false;
            }
            else {
		if (right - left > max_cnt)
		    max_cnt = right - left;
                right++;
		right_slided = true;
            }
        }
        return max_cnt;
}

int main() {
	cout << lengthOfLongestSubstringKDistinct("eceba", 2) << endl;
	cout << lengthOfLongestSubstringKDistinct("aa", 1) << endl;
	cout << lengthOfLongestSubstringKDistinct("ee", 0) << endl;
}
