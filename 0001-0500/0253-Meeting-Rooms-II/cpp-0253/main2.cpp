/// Source : https://leetcode.com/problems/meeting-rooms-ii/description/
/// Author : liuyubobobo
/// Time   : 2018-09-10

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Simulation
/// Using Priority Queue
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

private:
    class CompareInterval{
    public:
        bool operator()(const Interval& a, const Interval& b){
            return a.end > b.end;
        }
    };

public:
    int minMeetingRooms(vector<Interval>& intervals) {

        sort(intervals.begin(), intervals.end(), cmpIntervals);

        priority_queue<Interval, vector<Interval>, CompareInterval> rooms;
        int res = 0;
        for(const Interval& meeting: intervals){

            while(!rooms.empty() && rooms.top().end <= meeting.start)
                rooms.pop();

            rooms.push(meeting);
            res = max(res, (int)rooms.size());
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