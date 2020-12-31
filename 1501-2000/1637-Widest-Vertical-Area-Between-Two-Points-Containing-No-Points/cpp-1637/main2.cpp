/// Source : https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/
/// Author : liuyubobobo
/// Time   : 2020-10-31

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {

        sort(points.begin(), points.end());

        int last = points[0][0], res = 0;
        for(const vector<int>& p: points){
            res = max(res, p[0] - last);
            last = p[0];
        }
        return res;
    }
};


int main() {

    return 0;
}
