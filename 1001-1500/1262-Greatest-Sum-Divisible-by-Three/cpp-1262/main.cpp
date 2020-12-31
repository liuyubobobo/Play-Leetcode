/// Source : https://leetcode.com/problems/greatest-sum-divisible-by-three/
/// Author : liuyubobobo
/// Time   : 2020-02-17

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(3n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        vector<int> res(3, 0), t(3, 0);
        for(int e: nums){
            for(int mod = 0; mod < 3; mod ++)
                t[(res[mod] + e) % 3] = max(t[(res[mod] + e) % 3], res[mod] + e);
            res = t;
        }

        return res[0];
    }
};


int main() {

    vector<int> nums1 = {3,6,5,1,8};
    cout << Solution().maxSumDivThree(nums1) << endl;
    // 18

    vector<int> nums2 = {1,2,3,4,4};
    cout << Solution().maxSumDivThree(nums2) << endl;
    // 12

    vector<int> nums3 = {2,3,36,8,32,38,3,30,13,40};
    cout << Solution().maxSumDivThree(nums3) << endl;
    // 195

    return 0;
}
