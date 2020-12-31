/// Source : https://leetcode.com/problems/container-with-most-water/
/// Author : liuyubobobo
/// Time   : 2018-08-13

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {

        assert(height.size() >= 2);

        int area = 0;
        for(int i = 0 ; i < height.size() ; i ++)
            for(int j = i + 1; j < height.size() ; j ++)
                area = max(area , min(height[i], height[j]) * (j - i));
        return area;
    }
};


int main() {

    vector<int> nums1 = {1, 1};
    cout << Solution().maxArea(nums1) << endl;

    return 0;
}