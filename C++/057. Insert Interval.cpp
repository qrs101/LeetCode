#include <iostream>
#include <vector>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    std::vector<Interval> insert(std::vector<Interval>& intervals, Interval newInterval) {
        std::vector<Interval> res;
        int i;
        for (i = 0 ; i < intervals.size(); i++) {
            if (newInterval.start <= intervals[i].end) {
                if (newInterval.start > intervals[i].start)
                    newInterval.start = intervals[i].start;
                break;
            }
        }
        res.insert(res.end(), intervals.begin(), intervals.begin() + i);
        for (i = int(intervals.size()) - 1; i >= 0; i--) {
            if (newInterval.end >= intervals[i].start) {
                if (newInterval.end < intervals[i].end)
                    newInterval.end = intervals[i].end;
                break;
            }
        }
        res.emplace_back(newInterval);
        res.insert(res.end(), intervals.begin() + i + 1, intervals.end());
        return res;
    }
};