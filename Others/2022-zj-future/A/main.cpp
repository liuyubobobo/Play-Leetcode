/// Source : https://leetcode.cn/contest/zj-future2022/problems/WYKGLO/
/// Author : liuyubobobo
/// Time   : 2022-07-08

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    bool canReceiveAllSignals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        for(int i = 1; i < intervals.size(); i ++){
            int s1 = intervals[i - 1][0], e1 = intervals[i - 1][1];
            int s2 = intervals[i][0], e2 = intervals[i][1];
            if(s2 < e1) return false;
        }
        return true;
    }
};


int main() {

    return 0;
}
