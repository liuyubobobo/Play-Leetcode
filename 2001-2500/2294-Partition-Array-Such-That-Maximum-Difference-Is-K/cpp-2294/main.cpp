/// Source : https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/
/// Author : liuyubobobo
/// Time   : 2022-06-04

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int res = 0;
        for(int start = 0, i = 1; i <= nums.size(); i ++)
            if(i == nums.size() || nums[i] - nums[start] > k){
                res ++;
                start = i;
            }
        return res;
    }
};


int main() {

    return 0;
}
