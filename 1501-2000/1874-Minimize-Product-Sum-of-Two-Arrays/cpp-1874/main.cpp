/// Source : https://leetcode.com/problems/minimize-product-sum-of-two-arrays/
/// Author : liuyubobobo
/// Time   : 2021-05-27

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(), nums1.end());
        sort(nums2.rbegin(), nums2.rend());

        int res = 0;
        for(int i = 0; i < nums1.size(); i ++)
            res += nums1[i] * nums2[i];
        return res;
    }
};


int main() {

    return 0;
}
