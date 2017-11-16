/// Source : https://leetcode.com/problems/merge-intervals/description/
/// Author : liuyubobobo
/// Time   : 2017-11-15

#include <iostream>
#include <vector>

using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}

    friend ostream& operator<<(ostream& os, const Interval& interval){
        os << "[" << interval.start << "," << interval.end << "]";
        return os;
    }
};

bool intervalCmp(const Interval& interval1, const Interval& interval2){

    if(interval1.start != interval2.start)
        return interval1.start < interval2.start;
    return interval1.end < interval2.end;
}

/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {

        if(intervals.size() <= 1)
            return intervals;

        sort(intervals.begin(), intervals.end(), intervalCmp);

        vector<Interval> res;
        res.push_back(intervals[0]);
        for(int i = 1 ; i < intervals.size() ; i ++){
            if(cross(res.back(), intervals[i])){
                Interval newInterval = mergeInterval(res.back(), intervals[i]);
                res.pop_back();
                res.push_back(newInterval);
            }
            else
                res.push_back(intervals[i]);
        }

        return res;
    }

private:
    bool cross(const Interval& interval1, const Interval& interval2){
        return interval2.start <= interval1.end;
    }

    Interval mergeInterval(const Interval& interval1, const Interval& interval2){
        return Interval(min(interval1.start, interval2.start),
                        max(interval1.end, interval2.end));
    }
};


void printIntervals(const vector<Interval>& vec){
    for(Interval interval: vec)
        cout << interval << " ";
    cout << endl;
}

int main() {

    vector<Interval> vec1;
    vec1.push_back(Interval(1, 3));
    vec1.push_back(Interval(2, 6));
    vec1.push_back(Interval(8, 10));
    vec1.push_back(Interval(15, 18));

    printIntervals(Solution().merge(vec1));
    // [1,6] [8,10] [15,18]

    // ---

    vector<Interval> vec2;
    vec2.push_back(Interval(1, 4));
    vec2.push_back(Interval(0, 0));

    printIntervals(Solution().merge(vec2));
    // [0,0] [1,4]

    return 0;
}