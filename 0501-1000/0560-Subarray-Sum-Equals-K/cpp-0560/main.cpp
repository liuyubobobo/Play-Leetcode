/// Source : https://leetcode.com/problems/subarray-sum-equals-k/
/// Author : liuyubobobo
/// Time   : 2021-04-17

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Presum + HashMap
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        vector<int> presum(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i ++)
            presum[i + 1] = presum[i] + nums[i];

        unordered_map<int, int> table;
        table[0] ++;

        int res = 0;
        for(int i = 0; i < nums.size(); i ++){
            res += table[presum[i + 1] - k];
            table[presum[i + 1]] ++;
        }
        return res;
    }
};


int main() {

//    vector<int> nums1 = {-1, -1, 1};
//    cout << Solution().subarraySum(nums1, 0) << endl;
//    // 1

    vector<int> nums2 = {1, -1, 0};
    cout << Solution().subarraySum(nums2, 0) << endl;
    // 3

    return 0;
}
