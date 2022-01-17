/// Source : https://leetcode.com/problems/minimum-time-difference/
/// Author : liuyubobobo
/// Time   : 2022-01-17

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Compelexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        int n = timePoints.size();

        vector<int> t(n);
        for(int i = 0; i < n; i ++)
            t[i] = atoi(timePoints[i].substr(0, 2).c_str()) * 60 + atoi(timePoints[i].substr(3).c_str());

        sort(t.begin(), t.end());

        int res = INT_MAX;
        for(int i = 1; i < timePoints.size(); i ++)
            res = min(res, t[i] - t[i - 1]);
        res = min(res, t[0] - t.back() + 24 * 60);
        return res;
    }
};


int main() {

    return 0;
}
