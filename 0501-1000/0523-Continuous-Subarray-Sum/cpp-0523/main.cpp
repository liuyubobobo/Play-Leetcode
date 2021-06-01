/// Source : https://leetcode.com/problems/continuous-subarray-sum/
/// Author : liuyubobobo
/// Time   : 2021-06-01

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Using HashSet
/// Time Complexity: O(n)
/// Space Complexity: O(k)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        unordered_set<int> table;
        table.insert(0);

        int sum = 0;
        for(int i = 1; i < nums.size(); i ++){
            if(table.count((sum + nums[i - 1] + nums[i]) % k))
                return true;

            sum += nums[i - 1];
            table.insert(sum % k);
        }
        return false;
    }
};


int main() {

    vector<int> nums1 = {23,2,6,4,7};
    cout << Solution().checkSubarraySum(nums1, 13) << endl;
    // 0

    return 0;
}
