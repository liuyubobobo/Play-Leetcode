/// Source : https://leetcode.com/problems/partition-equal-subset-sum/description/
/// Author : liuyubobobo
/// Time   : 2017-11-19

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Memory Search
/// Time Complexity: O(len(nums) * O(sum(nums)))
/// Space Complexity: O(len(nums) * O(sum(nums)))
class Solution {

private:
    // memo[i][c]: using nums[0...i] to fill a back knapsack with space c
    vector<vector<int>> memo;

    bool tryPartition(const vector<int> &nums, int index, int sum){

        if(sum == 0)
            return true;

        if(sum < 0 || index < 0)
            return false;

        if(memo[index][sum] != -1)
            return memo[index][sum] == 1;

        memo[index][sum] = (tryPartition(nums, index - 1, sum) ||
               tryPartition(nums, index - 1, sum - nums[index])) ? 1 : 0;

        return memo[index][sum] == 1;
    }

public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i ++){
            assert(nums[i] > 0);
            sum += nums[i];
        }

        if(sum % 2)
            return false;

        memo.clear();
        for(int i = 0 ; i < nums.size() ; i ++)
            memo.push_back(vector<int>(sum / 2 + 1, -1));
        return tryPartition(nums, nums.size() - 1, sum / 2);
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