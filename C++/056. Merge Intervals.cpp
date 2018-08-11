#include <iostream>
#include <algorithm>
#include <vector>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    std::vector<Interval> merge(std::vector<Interval>& intervals) {
        std::vector<Interval> res;
        if (intervals.size() == 0)
            return res;
        sort(intervals.begin(), intervals.end(), compare);
        Interval interval(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (interval.end >= intervals[i].start) {
                if (interval.end < intervals[i].end)
                    interval.end = intervals[i].end;
            } else {
                res.emplace_back(interval);
                interval = intervals[i];
            }
        }
        res.emplace_back(interval);
        return res;
    }

    static bool compare(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
};