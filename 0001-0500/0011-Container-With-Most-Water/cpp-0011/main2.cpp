/// Source : https://leetcode.com/problems/container-with-most-water/
/// Author : liuyubobobo
/// Time   : 2016-12-26

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Two Pointers
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {

        assert(height.size() >= 2);

        int l = 0, r = height.size() - 1;
        int area = 0;
        while(l < r){
            area = max(area , min(height[l], height[r]) * (r - l));
            if(height[l] < height[r])
                l ++;
            else
                r --;
        }
        return area;
    }
};


int main() {

    vector<int> nums1 = {1, 1};
    cout << Solution().maxArea(nums1) << endl;

    return 0;
}