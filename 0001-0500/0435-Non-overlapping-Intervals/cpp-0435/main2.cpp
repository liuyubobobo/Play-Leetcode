/// https://leetcode.com/problems/non-overlapping-intervals/description/
/// Author : liuyubobobo
/// Time   : 2017-11-19
/// Updated: 2019-09-22

#include <iostream>
#include <vector>

using namespace std;


/// Greedy Algorithm based on starting point
/// Time Complexity:  O(n)
/// Space Complexity: O(n)
class Solution {

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals){

        if(intervals.size() == 0)
            return 0;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });

        int res = 1;
        int pre = 0;
        for(int i = 1 ; i < intervals.size() ; i ++)
            if(intervals[i][0] >= intervals[pre][1]){
                pre = i;
                res ++;
            }
            else if(intervals[i][1] < intervals[pre][1])
                pre = i;

        return intervals.size() - res;
    }
};


int main() {

    vector<vector<int>> interval1 = {{1,2}, {2,3}, {3,4}, {1,3}};
    cout << Solution().eraseOverlapIntervals(interval1) << endl;

    vector<vector<int>> interval2 = {{1,2}, {1,2}, {1,2}};
    cout << Solution().eraseOverlapIntervals(interval2) << endl;

    vector<vector<int>> interval3 = {{1,2}, {2,3}};
    cout << Solution().eraseOverlapIntervals(interval3) << endl;

    return 0;
}