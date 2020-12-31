/// Source : https://leetcode.com/problems/trapping-rain-water/description/
/// Author : liuyubobobo
/// Time   : 2018-09-16

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int trap(vector<int>& height) {

        if(height.size() <= 2)
            return 0;

        int res = 0;
        for(int i = 1; i < height.size() - 1; i ++) {
            int lmax = height[i], rmax = height[i];
            for (int l = i - 1; l >= 0; l --)
                lmax = max(lmax, height[l]);
            for(int r = i + 1; r < height.size(); r ++)
                rmax = max(rmax, height[r]);
            res += min(lmax, rmax) - height[i];
        }
        return res;
    }
};


int main() {

    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << Solution().trap(height1) << endl;
    // 6

    vector<int> height2 = {4,2,3};
    cout << Solution().trap(height2) << endl;
    // 1

    vector<int> height3 = {4, 2, 0, 3, 2, 5};
    cout << Solution().trap(height3) << endl;
    // 9

    return 0;
}