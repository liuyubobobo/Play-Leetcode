/// Source : https://leetcode.com/problems/meeting-rooms/description/
/// Author : liuyubobobo
/// Time   : 2018-09-10

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force see if overlapped for every two intervals
/// Time Complexity: O(n^2)
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

        for(int i = 0; i < intervals.size(); i ++)
            for(int j = i + 1; j < intervals.size(); j ++)
                if(overlapped(intervals[i], intervals[j]))
                    return false;
        return true;
    }

private:
    bool overlapped(const Interval& i1, const Interval& i2){
        return max(i1.start, i2.start) < min(i1.end, i2.end);
    }
};


int main() {

    return 0;
}