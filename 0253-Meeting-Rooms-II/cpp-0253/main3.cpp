/// Source : https://leetcode.com/problems/meeting-rooms-ii/description/
/// Author : liuyubobobo
/// Time   : 2018-09-10

#include <iostream>
#include <vector>

using namespace std;


/// Two Pointers
/// Sorting start time and end time seperately.
///
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)

/// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        if(intervals.size() == 0)
            return 0;

        vector<int> starts, ends;
        for(const Interval& interval: intervals){
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());


        int res = 1, sz = 1;
        int end_index = 0;
        for(int start_index = 1; start_index < starts.size(); start_index ++){
            while(end_index < ends.size() && ends[end_index] <= starts[start_index])
                end_index ++, sz --;
            sz ++;
            res = max(res, sz);
        }

        return res;
    }
};


int main() {

    return 0;
}