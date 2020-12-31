/// Source : https://leetcode.com/problems/meeting-rooms-ii/description/
/// Author : liuyubobobo
/// Time   : 2018-09-10

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n^2)
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

        sort(intervals.begin(), intervals.end(), cmpIntervals);

        vector<Interval> rooms;
        int sz = 0, res = 0;
        for(const Interval& meeting: intervals){

            for(Interval& room: rooms)
                if(room.end != -1 && room.end <= meeting.start){
                    room.start = room.end = -1;
                    sz --;
                }

            bool ok = false;
            for(Interval& room: rooms)
                if(room.start == -1){
                    room = meeting;
                    ok = true;
                    break;
                }
            if(!ok)
                rooms.push_back(meeting);
            sz ++;

            res = max(res, sz);
        }

        return res;
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