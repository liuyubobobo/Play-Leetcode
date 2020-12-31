/// Source : https://leetcode.com/problems/meeting-rooms-ii/description/
/// Author : liuyubobobo
/// Time   : 2018-09-10

#include <iostream>
#include <vector>

using namespace std;


/// Dealing with start time and end time seperately
/// make start time and end time in a pair structure
/// and deal with them in one single vector:)
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

        vector<pair<int, char>> timepoints;
        for(const Interval& interval: intervals){
            timepoints.push_back(make_pair(interval.start, 's'));
            timepoints.push_back(make_pair(interval.end, 'e'));
        }
        sort(timepoints.begin(), timepoints.end());

        int res = 0;
        int cur = 0;
        for(const pair<int, char>& p: timepoints)
            if(p.second == 's'){
                cur ++;
                res = max(res, cur);
            }
            else
                cur --;

        return res;
    }
};


int main() {

    return 0;
}