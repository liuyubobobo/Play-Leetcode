/// Source : https://leetcode.com/problems/meeting-rooms/description/
/// Author : liuyubobobo
/// Time   : 2018-09-10

#include <iostream>
#include <vector>

using namespace std;


/// Sorting and see if overlapped linearly
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)

/// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {

        sort(intervals.begin(), intervals.end(), cmpIntervals);
        for(int i = 1; i < intervals.size(); i ++)
            if(intervals[i].start < intervals[i - 1].end)
                return false;
        return true;
    }

private:
    static bool cmpIntervals(const Interval& i1, const Interval& i2){
        if(i1.start != i2.start)
            return i1.start < i2.start;
        return i1.end < i2.end;
    }
};


int main() {

    return 0;
}