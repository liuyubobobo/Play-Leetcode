/// Source : https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
/// Author : liuyubobobo
/// Time   : 2017-10-16

#include <iostream>
#include <vector>
#include <cassert>
#include <numeric>
#include <algorithm>

using namespace std;

/// Memory Search
/// We don't need to care about how many subset we didn't fill
///
/// Time Complexity: O((2^len(nums)) * len(nums))
/// Space Complexity: O((2^len(nums)))
class Solution {

private:
    int subsum = 0;
    bool dp[1<<16];
    bool visited[1<<16];

public:

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sum = accumulate(nums.begin(), nums.end(), 0);
        // cout << "sum = " << sum << endl;
        if(sum % k != 0)
            return false;

        subsum = sum / k;
        // cout << subsum << endl;

        sort(nums.begin(), nums.end());
        if(nums[nums.size()-1] > subsum)
            return false;

        int len = (1<<nums.size());
        // cout << len << endl;

        for(int i = 0 ; i < len ; i ++){
            dp[i] = false;
            visited[i] = false;
        }

        return solve(nums, 0);
    }

private:

    bool solve(const vector<int>& nums, int state){

        if(state == (1<<nums.size()) - 1)
            return true;

        if(visited[state])
            return dp[state];

        visited[state] = true;
        return dp[state] = findSum(nums, state, 0, subsum);
    }

    bool findSum(const vector<int>& nums,
                 int state, int startIndex, int todo){

        if(todo == 0)
            return solve(nums, state);

        for(int i = startIndex; i < nums.size() ; i ++)
            if(todo >= nums[i]){
                if((state & (1<<i)) == 0 && findSum(nums, state|(1<<i), i+1, todo-nums[i]))
                    return true;
            }
            else
                break;

        return false;
    }
};

int main() {

    int arr1[] = {4, 3, 2, 3, 5, 2, 1};
    vector<int> vec1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    int k1 = 4;
    if(Solution().canPartitionKSubsets(vec1, k1))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    int arr2[] = {71,85,99,110,27,47,8,83,72,24,52,17,99};
    vector<int> vec2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    int k2 = 13;
    if(Solution().canPartitionKSubsets(vec2, k2))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    int arr3[] = {39, 73, 52, 3, 9370};
    vector<int> vec3(arr3, arr3 + sizeof(arr3) / sizeof(int));
    int k3 = 3;
    if(Solution().canPartitionKSubsets(vec3, k3))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}