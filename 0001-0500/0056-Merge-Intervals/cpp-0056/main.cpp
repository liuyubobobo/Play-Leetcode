/// Source : https://leetcode.com/problems/merge-intervals/description/
/// Author : liuyubobobo
/// Time   : 2017-11-15
/// Updated: 2019-05-23

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if(intervals.size() <= 1)
            return intervals;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] != b[0])
                return a[0] < b[0];
            return a[1] < b[1];
        });

        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i = 1 ; i < intervals.size() ; i ++){
            if(cross(res.back(), intervals[i])){
                vector<int> newInterval = mergeInterval(res.back(), intervals[i]);
                res.pop_back();
                res.push_back(newInterval);
            }
            else
                res.push_back(intervals[i]);
        }

        return res;
    }

private:
    bool cross(const vector<int>& interval1, const vector<int>& interval2){
        return interval2[0] <= interval1[1];
    }

    vector<int> mergeInterval(const vector<int>& interval1, const vector<int>& interval2){
        return {min(interval1[0], interval2[0]), max(interval1[1], interval2[1])};
    }
};


void printIntervals(const vector<vector<int>>& vec){
    for(const vector<int>& interval: vec)
        cout << interval[0] << " " << interval[1] << endl;
    cout << endl;
}

int main() {

    vector<vector<int>> vec1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    printIntervals(Solution().merge(vec1));
    // [1,6] [8,10] [15,18]

    // ---

    vector<vector<int>> vec2 = {{1, 4}, {0, 0}};
    printIntervals(Solution().merge(vec2));
    // [0,0] [1,4]

    return 0;
}