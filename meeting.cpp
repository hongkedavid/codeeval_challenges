#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

   bool comp_start(const vector<int>& lhs, const vector<int>& rhs) {
        if (lhs[0] < rhs[0])
            return true;
        else if (lhs[0] == rhs[0])
            return (lhs[1] < rhs[1]);
        else 
            return false;
    }
    bool comp_end(const vector<int>& lhs, const vector<int>& rhs) {
        if (lhs[1] < rhs[1])
            return true;
        else if (lhs[1] == rhs[1])
            return (lhs[0] < rhs[0]);
        else 
            return false;
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), comp_start);
        int max_cnt = 1;
        priority_queue<vector<int>, vector<vector<int>>, comp_end> ongoing;
        ongoing.push(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            while (!ongoing.empty()) {
                int prev = ongoing.top();
                if (intervals[prev][1] <= intervals[i][0])
                    ongoing.pop();
                else
                    break;
            }
            ongoing.push(intervals[i]);
            if (ongoing.size() > max_cnt)
                max_cnt = ongoing.size();
        }
        return max_cnt;
    }

