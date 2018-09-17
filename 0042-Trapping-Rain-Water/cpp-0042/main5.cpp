/// Source : https://leetcode.com/problems/trapping-rain-water/description/
/// Author : liuyubobobo
/// Time   : 2018-09-16

#include <iostream>
#include <vector>

using namespace std;


/// Two Pointers
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int trap(vector<int>& height) {

        if(height.size() <= 2)
            return 0;

        int res = 0;
        int l = 0, r = height.size() - 1, lmax_i = l, rmax_i = r;
        while(l < r){
            if(height[l] < height[r]){
                l ++;
                if(height[l] < height[lmax_i])
                    res += min(height[lmax_i], height[rmax_i]) - height[l];
                else
                    lmax_i = l;
            }
            else{
                r --;
                if(height[r] < height[rmax_i])
                    res += min(height[lmax_i], height[rmax_i]) - height[r];
                else
                    rmax_i = r;
            }
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