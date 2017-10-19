/// Source : https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
/// Author : liuyubobobo
/// Time   : 2017-10-15

#include <iostream>
#include <vector>
#include <cassert>
#include <numeric>

using namespace std;

/// Memory Search
/// Time Complexity: O((2^len(nums)) * len(nums) * k)
/// Space Complexity: O((2^len(nums)) * k)
class Solution {

private:
    int subsum = 0;
    bool dp[1<<16][17];
    bool visited[1<<16][17];

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

        for(int i = 0 ; i < len ; i ++)
            for(int j = 0 ; j <= k ; j ++){
                dp[i][j] = false;
                visited[i][j] = false;
            }

        return solve(nums, 0, k);
    }

private:

    bool solve(const vector<int>& nums, int state, int left){

        if(left == 0){
            assert(state == (1<<nums.size()) - 1 &&
                           "Not all numbers used when left == 0.");
            return true;
        }

        if(visited[state][left])
            return dp[state][left];

        visited[state][left] = true;
        return dp[state][left] = findSum(nums, state, 0, subsum, left);
    }

    bool findSum(const vector<int>& nums,
                 int status, int startIndex, int todo, int left){

        if(todo == 0)
            return solve(nums, status, left-1);

        for(int i = startIndex; i < nums.size() ; i ++)
            if(todo >= nums[i]){
                if((status & (1<<i)) == 0 && findSum(nums, status|(1<<i), i+1, todo-nums[i], left))
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