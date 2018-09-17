/// Source : https://leetcode.com/problems/trapping-rain-water/description/
/// Author : liuyubobobo
/// Time   : 2018-09-16

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int trap(vector<int>& height) {

        if(height.size() <= 2)
            return 0;

        vector<int> rdp(height.size(), height.back());
        for(int i = height.size() - 2; i >= 0; i --)
            rdp[i] = max(height[i], rdp[i + 1]);

        vector<int> ldp(height.size(), height[0]);
        for(int i = 1; i < height.size(); i ++)
            ldp[i] = max(height[i], ldp[i - 1]);

        int res = 0;
        for(int i = 0; i < height.size(); i ++)
            res += min(ldp[i], rdp[i]) - height[i];
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