#include <iostream>
#include <algorithm>
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
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0 || intervals.size() == 1)
            return intervals;
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), compare);
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

    static bool compare(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
};