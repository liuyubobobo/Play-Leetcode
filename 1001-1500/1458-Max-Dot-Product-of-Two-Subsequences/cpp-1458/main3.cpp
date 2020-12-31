/// Source : https://leetcode.com/problems/max-dot-product-of-two-subsequences/
/// Author : liuyubobobo
/// Time   : 2020-05-24

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming + Rolling Array
/// Time Complexity: O(n1 * n2)
/// Space Complexity: O(n2)
class Solution {

public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> dp(n2 + 1, -1e9);

        for(int i = 0; i < n1; i ++){
            vector<int> tdp(n2 + 1, -1e9);
            for(int j = 0; j < n2; j ++){
                tdp[j + 1] = nums1[i] * nums2[j];
                tdp[j + 1] = max(tdp[j + 1], nums1[i] * nums2[j] + dp[j]);
                tdp[j + 1] = max(tdp[j + 1], dp[j]);
                tdp[j + 1] = max(tdp[j + 1], dp[j + 1]);
                tdp[j + 1] = max(tdp[j + 1], tdp[j]);
            }
            dp = tdp;
        }
        return dp[n2];
    }
};


int main() {

    vector<int> nums11 = {2,1,-2,5}, nums21 = {3,0,-6};
    cout << Solution().maxDotProduct(nums11, nums21) << endl;
    // 18

    vector<int> nums12 = {3, -2}, nums22 = {2, -6, 7};
    cout << Solution().maxDotProduct(nums12, nums22) << endl;
    // 21

    vector<int> nums13 = {-1, -1}, nums23 = {1, 1};
    cout << Solution().maxDotProduct(nums13, nums23) << endl;
    // -1

    vector<int> nums14 = {-5, -1, -2}, nums24 = {3, 3, 5, 5};
    cout << Solution().maxDotProduct(nums14, nums24) << endl;
    // -3

    vector<int> nums15 = {-5, -1, -2}, nums25 = {3, 5};
    cout << Solution().maxDotProduct(nums15, nums25) << endl;
    // -3

    return 0;
}
