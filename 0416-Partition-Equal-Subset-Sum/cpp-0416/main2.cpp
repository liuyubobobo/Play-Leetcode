/// Source : https://leetcode.com/problems/partition-equal-subset-sum/description/
/// Author : liuyubobobo
/// Time   : 2017-11-19

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Dynamic Programming
/// Time Complexity: O(len(nums) * O(sum(nums)))
/// Space Complexity: O(len(nums) * O(sum(nums)))
class Solution {

public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i ++){
            assert(nums[i] > 0);
            sum += nums[i];
        }

        if(sum % 2)
            return false;

        int n = nums.size();
        int C = sum / 2;
        vector<bool> memo(C + 1, false);
        for(int i = 0 ; i <= C ; i ++)
            memo[i] = (nums[0] == i);

        for(int i = 1 ; i < n ; i ++)
            for(int j = C; j >= nums[i] ; j --)
                memo[j] = memo[j] || memo[j - nums[i]];

        return memo[C];
    }
};

void printBool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    int nums1[] = {1, 5, 11, 5};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));
    printBool(Solution().canPartition(vec1));

    int nums2[] = {1, 2, 3, 5};
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));
    printBool(Solution().canPartition(vec2));

    return 0;
}