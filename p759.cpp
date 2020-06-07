/*
Employee Free Time
We are given a list schedule of employees, which represents the working time for each employee.
Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.
Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.
(Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined).  Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.
 
Example 1:
Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
Explanation: There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.

Example 2:
Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
Output: [[5,6],[7,9]]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Interval {
  public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
    
static bool comp(Interval& lhs, Interval& rhs) {
        if (lhs.start < rhs.start)
            return true;
        else if (lhs.start == rhs.start)
            return (lhs.end < rhs.end);
        else
            return false;    
}
    
vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> out;
        if (schedule.size() == 0)
            return out;
        sort(schedule[0].begin(), schedule[0].end(), comp);
        vector<Interval> curr = schedule[0];
        for (int i = 1; i < schedule.size(); i++) {
            sort(schedule[i].begin(), schedule[i].end(), comp);
            int l1 = 0, l2 = 0;
            vector<Interval> tmp;
            while (l1 < curr.size() && l2 < schedule[i].size()) {
                if (curr[l1].start > schedule[i][l2].end) {
                    tmp.push_back(schedule[i][l2]);
                    l2++;
                }
                else if (curr[l1].end < schedule[i][l2].start) {
                    tmp.push_back(curr[l1]);
                    l1++;
                }
                else {
                    if (curr[l1].end > schedule[i][l2].end) {
                        tmp.push_back({min(curr[l1].start, schedule[i][l2].start), schedule[i][l2].end});
                        curr[l1].start = schedule[i][l2].end;
                        l2++;
                    }
                    else if (curr[l1].end < schedule[i][l2].end) {
                        tmp.push_back({min(curr[l1].start, schedule[i][l2].start), curr[l1].end});
                        schedule[i][l2].start = curr[l1].end;
                        l1++;
                    }
                    else {
                        tmp.push_back({min(curr[l1].start, schedule[i][l2].start), curr[l1].end});
                        l1++;
                        l2++;
                    }
                }
            }
            while (l1 < curr.size()) {
                tmp.push_back(curr[l1]);
                l1++;
            }
            while (l2 < schedule[i].size()) {
                tmp.push_back(schedule[i][l2]);
                l2++;
            }
            curr = tmp;
        }
        for (int i = 1; i < curr.size(); i++)
            if (curr[i].start > curr[i-1].end)
                out.push_back({curr[i-1].end, curr[i].start});
        return out;
}

int main() {
	vector<vector<Interval>> s1 = {{{1,2},{5,6}}, {{1,3}}, {{4,10}}};
	vector<Interval> o1 = employeeFreeTime(s1);
        for (auto o : o1)
	     cout << o.start << "," << o.end << " ";
	cout << endl;
	vector<vector<Interval>> s2 = {{{1,3},{6,7}}, {{2,4}}, {{2,5},{9,12}}};
        vector<Interval> o2 = employeeFreeTime(s2);
        for (auto o : o2)
             cout << o.start << "," << o.end << " ";
        cout << endl;
}
