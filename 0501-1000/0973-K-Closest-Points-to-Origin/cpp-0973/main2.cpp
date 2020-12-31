/// Source : https://leetcode.com/problems/k-closest-points-to-origin/
/// Author : liuyubobobo
/// Time   : 2019-01-12

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Sorting in the original array directly
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [](const vector<int>& pa, const vector<int>& pb){
            return pa[0] * pa[0] + pa[1] * pa[1] <= pb[0] * pb[0] + pb[1] * pb[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};


int main() {

    return 0;
}