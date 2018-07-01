#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        if (intervals.size() == 0) {
            ans.push_back(newInterval);
            return ans;
        }
        for (int i = 0 ; i < intervals.size(); i++) {
            if (newInterval.start <= intervals[i].start) {
                intervals.insert(intervals.begin() + i, newInterval);
                break;
            }
        }
        if (newInterval.start > intervals[intervals.size() - 1].start)
            intervals.insert(intervals.end(), newInterval);

        for (int i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i + 1].start > intervals[i].end)
                ans.push_back(intervals[i]);
            else {
                if (intervals[i + 1].end <= intervals[i].end)
                    intervals[i + 1].end = intervals[i].end;
                intervals[i + 1].start = intervals[i].start;
            }
        }
        ans.push_back(intervals[intervals.size() - 1]);
        return ans;
    }
};