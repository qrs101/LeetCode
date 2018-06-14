#include<iostream>
#include<vector>
#include<map>
using namespace std;

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            map<long double, int> m;
            int res_ = 0;
            int limit_k = 0;
            int coincide = 1;
            for (int j = i + 1; j < points.size(); j++) {
                long double k;
                if (points[j].x == points[i].x && points[j].y == points[i].y)
                    coincide++;
                else if (points[j].x == points[i].x)
                    limit_k++;
                else {
                    k = (long double)(points[j].y - points[i].y) / (long double)(points[j].x - points[i].x);
                    if (m.find(k) == m.end())
                        m.insert(map<long double, int>::value_type(k, 1));
                    else
                        m[k]++;
                }
            }
            for (auto num : m)
                if (res_ < num.second)
                    res_ = num.second;
            if (res_ < limit_k)
                res_ = limit_k;
            res_ += coincide;
            if (res < res_)
                res = res_;
        }  
        return res;
    }
};