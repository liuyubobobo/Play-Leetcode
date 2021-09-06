/// Source : https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
/// Author : liuyubobobo
/// Time   : 2021-09-06

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(), points.end());
        pair<int, int> cur = {points[0][0], points[0][1]};

        int res = 0;
        for(int i = 1; i < points.size(); i ++){
            vector<int> p = points[i];
            if(p[0] > cur.second) res ++, cur = {p[0], p[1]};
            else cur.first = min(cur.first, p[0]), cur.second = min(cur.second, p[1]);
        }
        res ++;
        return res;
    }
};


int main() {

    vector<vector<int>> points1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << Solution().findMinArrowShots(points1) << endl;
    // 2

    return 0;
}
